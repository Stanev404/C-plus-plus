#include <iostream>
#include <string>

using namespace std;

class CData{
public:
    CData(){
    value = 0;
    }
    CData(int val){
    value = val;
    }
    int value;
};
class CNode{
public:
    CNode(){
        left = NULL;
        right = NULL;
    };

    CNode(CData data)  {
        this->data=data;
        left = NULL;
        right = NULL;
    };
    ~CNode(){}


    CData data;
    CNode * left;
    CNode * right;

};

class CTree{
public:
    CTree(){};
    virtual ~CTree() = 0;

    virtual void preorder() = 0;
    virtual void inorder() = 0;
    virtual void postorder() = 0;

    virtual void save_to_file(string file_name) = 0;
    virtual void load_from_file(string file_name) = 0;
};

class CMTree : public CTree{
public:
    CMTree(){
    root = NULL;
    };
    virtual ~CMTree(){
    delete_branch(root);
    };
    void delete_branch(CNode *& pBr){ // & za da triem nego fakticheski, a ne novoto kopie
    if(pBr->left != NULL){
        delete_branch(pBr->left);
    }
    if(pBr->right != NULL){
        delete_branch(pBr->right);
    }
    delete pBr;
    pBr = NULL;
    }
    void preorder_branch(CNode * pBr){
    if(NULL == pBr){
        return;
    }
    cout << pBr->data.value << " ";
    preorder_branch(pBr->left);
    preorder_branch(pBr->right);
    }
    virtual void preorder(){
        preorder_branch(root);
    
    };
    void inorder_branch(CNode * pBr){
        if(NULL == pBr) return;

        inorder_branch(pBr->left);
        cout << pBr->data.value << " ";
        inorder_branch(pBr->right);
    }
    virtual void inorder(){
    inorder_branch(root);
    };
    virtual void postorder();

    virtual void save_to_file(string file_name);
    virtual void load_from_file(string file_name);
private:
    CNode * root;
};




int main()
{

    return 0;
}