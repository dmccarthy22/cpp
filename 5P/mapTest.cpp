/** CS515 Assignment 5P File: mapTest.cpp
Name: Dan McCarthy
Section: 1
Date: 10/10/18
*/
/* These are test for map inerface methods using Google Test */
#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

//The constructor should create a map with zero size
TEST(MapTest, constructorCreatesZeroSizeMap)
{ 
    Map testMap;
    EXPECT_EQ(0, testMap.size());
}

//Inserting into an empty map should return true and result in a size of one
TEST(MapTest, insertWhileEmptyReturnsTrueAndMapSizeIsOne)
{
    Map testMap;
    EXPECT_TRUE(testMap.insert("1", "3"));
    EXPECT_EQ(1, testMap.size());

}

//Inserting a key that already exists should fail and not change the map size
TEST(MapTest, insertOfSameKeyReturnsFalseAndMapSizeRemainsSame)
{
    Map testMap;
    testMap.insert("1", "3");
    EXPECT_FALSE(testMap.insert("1","3"));
    EXPECT_EQ(1, testMap.size());
}

//Accessing an existing item using [] should return correct value and not
//change the map size
TEST(MapTest, indexOperatorOfExistingKeyReturnsProperValueAndSizeIsSame)
{
    Map testMap;
    testMap.insert("1", "11");
    testMap.insert("2", "12");
    testMap.insert("3", "13");
    EXPECT_EQ("12", testMap["2"]);
    EXPECT_EQ(3, testMap.size());

}
    
//Using [] to set an item in an empty map should add the item with an
//appropriate value and increase the map size to one
TEST(MapTest, indexOperatorOnEmptyMapProperlySetsValueAndSizeIsOne)
{
    Map mapTest;

    mapTest["4"] = "k";
    EXPECT_EQ("k", mapTest["4"]);
    EXPECT_EQ(1, mapTest.size());


  

}

//Using [] to set an item in a map that already contains other items
//inserts and updates the size appropriately
TEST(MapTest, indexOperatorOnMissingKeyProperlySetsValueAndIncrementsSize)
{ 
    Map mapTest;
    


    mapTest.insert("1", "10");
    mapTest.insert("2", "11");
    mapTest["3"] = "12";
    EXPECT_EQ("12", mapTest["3"]);
    EXPECT_EQ(3, mapTest.size());
    

}

//Erasing a key that exists in the map succeeds and decrements the map size
TEST(MapTest, eraseOfExistingKeyReturnsTrueAndDecrementsSize)
{ 
    Map mapTest;

    mapTest.insert("1", "11");
    mapTest.insert("2", "12");
    mapTest.insert("3", "15");
    EXPECT_TRUE(mapTest.erase("2"));
    EXPECT_EQ(2, mapTest.size());

}

//Erase on an empty map fails and keeps the map size at zero
TEST(MapTest, eraseOnEmptyMapReturnsFalseAndSizeRemainsZero)
{ 
    Map emptyMap;
    EXPECT_FALSE(emptyMap.erase("4"));
    EXPECT_EQ(0, emptyMap.size());

}

//Erase of a non-existant key fails and does not change the map size
TEST(MapTest, eraseOfMissingKeyReturnsFalseAndSizeRemainsSame)
{ 
    Map mapTest;
    mapTest.insert("1", "11");
    mapTest.insert("2", "12");
    mapTest.insert("3", "13");
    mapTest.insert("4", "14");
    EXPECT_FALSE(mapTest.erase("5"));
    EXPECT_EQ(4, mapTest.size());



}

//Using the copy constructor results in two maps of the same, correct size
TEST(MapTest, copyConstructorMakesCorrectSize)
{
    Map map1;
    map1.insert("1", "11");
    map1.insert("2", "12");
    map1.insert("3", "13");
    Map map2(map1);
    EXPECT_EQ(3, map2.size());



}

//Using the copy constructor with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, copyConstructorMakesSeparateCopy)
{

    Map map1;
    map1.insert("1", "11");
    map1.insert("2", "12");
    map1.insert("3", "13");
    map1.insert("10", "100");
    Map map2(map1);
    
    //map2.erase("3");
    map1.erase("2");
    map1.erase("1");
    map2.insert("5", "15");
    map2["10"] = 99;

    EXPECT_EQ(2, map1.size());
    EXPECT_EQ(5, map2.size());
    EXPECT_FALSE(map1["10"]==map2["10"]);


}

//Using the assignment operator results in two maps of the same, correct size
TEST(MapTest, assignmentOperatorMakesCorrectSize)
{
    Map map1;
    map1.insert("1", "11");
    map1.insert("2", "12");
    map1.insert("3", "13");
    Map map2(map1);
    map1 = map2;
    EXPECT_EQ(3, map2.size());



}

//Using the assignment operator with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, assignmentMakesSeparateCopy)
{
    Map map1;
    map1.insert("1", "11");
    map1.insert("2", "12");
    map1.insert("3", "13");
    
    Map map2(map1);
    map2 = map1; 
    map1.insert("4", "14");
    map1.erase("2");
    map2["4"] = "33";
    EXPECT_EQ(3, map1.size());
    EXPECT_EQ(map1["1"], map2["1"]);

    EXPECT_EQ(4, map2.size());
   



}

//Using the assignment operator with an existing map with over 1000 items
//makes a copy that has correct keys/values at a couple of places deep within
//the map (values that aren't at either end of the range of keys used).
TEST(MapTest, assignmentWithManyItemsHasCorrectValues)
{
    Map map1;
    for (int i = 0; i < 1005; i++){
        string s = std::to_string(i);
        map1.insert(s, s);
    }
    EXPECT_EQ(1005, map1.size());
     Map map2;
     map2 = map1;
     EXPECT_EQ(1005, map2.size());
     EXPECT_EQ("68", map2["68"]);
     EXPECT_EQ("887", map2["887"]);
     EXPECT_EQ("999", map2["999"]);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
