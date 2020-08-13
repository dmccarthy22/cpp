/* CS515 Assignment 8
File: HuffTree.cpp
Name: Dan McCarthy
Section: 4
Collaboration Declaration:
          I received assistance from TA Ethan, the PAC, and collaborated with other students in PAC 
*/



#include "HuffTree.h"
//#include "PQueue.cpp"
#include "PQueue.h"
#include "string"



HuffTree::~HuffTree(){
   
}
void HuffTree::destructCode(HuffNode *&p)
{
    if (p->left != nullptr)
    {
        destructCode(p->left);
    }
    if (p->right != nullptr)
    {
        destructCode(p->right);
    }
    delete p;
}

string HuffTree::getCode(char j){
    string m = finder(j, _root, "");
   // cout <<m << endl;
    return m;

  

}
string HuffTree::finder(char j, HuffNode *n, string s){
    string ret = "";

    if(!n->left && !n->right){
        if(n->data == j){
            ret = s;
        }
    } else {
        if((ret = finder(j, n->left, s+"0"))== ""){
            ret = finder(j, n->right, s+"1");
        }
        if ((ret = finder(j, n->right, s + "1")) == "")
        {
            ret = finder(j, n->left, s + "0");
        }
    }
return ret;

/*    string k;
    if(!n->left&&!n->right){
        if (n->data ==look){
            return s;
        } else {
            return "";
        }
    }
    if (n->left){
        k = finder(look, n->left, s+"0");
        if (k!=""){
            return k;
        } else {
            k = finder(look, n->right, s+"1");
            return k;
        }
    }
    return s;
    */





 /*   if(n->left){
       finder(j, n->left, s+ "0");
    }
    if (n->right){
       finder(j, n->right, s+"1");
    }
    if (!n->left && !n->right && n->data == j){

       string k = s;

        return k;
       
    }
    return s;
    */
}

void HuffTree::buildTree(char *chs, int *freqs, int size){
    PQueue<HuffNode, 100> queue;
    for (int i = 0; i < size; i++){
        queue.insert(HuffNode(0,0,freqs[i], chs[i]));
        
    }

    
    while (queue.size()>1){   
        HuffNode *n1 = new HuffNode;
        *n1 = queue.findMin();
        queue.deleteMin();
        HuffNode *n2 = new HuffNode();
        *n2 = queue.findMin();
        queue.deleteMin();
        queue.insert(HuffNode(n1, n2, (n1->freq+n2->freq),0));

        }
    HuffNode root = queue.findMin();
    queue.deleteMin();
    _root = &root;
   //printTree(cout, 0, _root);
}

bool HuffNode::operator<(const HuffNode& h){
    if(freq < h.freq){
        return true;
    }
    return false;
}
bool HuffNode::operator>(const HuffNode &h)
{
    if (freq > h.freq)
    {
        return true;
    }
    return false;
}
bool HuffNode::operator<=(const HuffNode &h)
{
    if (freq <= h.freq)
    {
        return true;
    }
    return false;
}
bool HuffNode::operator>=(const HuffNode &h)
{
    if (freq >= h.freq)
    {
        return true;
    }
    return false;
}
void HuffTree::printTree(ostream &out, int level, HuffNode *p) const
{
    int i;
    if (p)
    {
        printTree(out, level + 1, p->right);
        for (i = 0; i < level; i++)
        {
            out << "\t";
        }
        out << p->freq << " " << p->data << '\n';
        printTree(out, level + 1, p->left);
    }
}


