#include <iostream>

using namespace std;

// struct Node{
//     int data;
//     struct Node* left;
//     struct Node* right;
// };


class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree(){
            root = 0;
        }

    // 루트노드가 root 인 이진검색트리에 데이터 data 를 입력하는 함수.
    Node* insert(Node* p, int data){
        if(p == 0){
            p = new Node(data);
            // p->left = 0;
            // p->right = 0;
            if(root == 0) root = p;
            // cout << p->data << endl;
        } 
        else if(data < p->data){
            p->left = insert(p->left, data);
        }
        else if(data > p->data){
            p->right = insert(p->right, data);
        }
        // cout << "p->l " << p->left << endl;
        return p;
    }


    // 루트노드가 root 인 이진검색트리를 전위(preorder) 탐색
    void preOrder(struct Node* p){
        if(root == NULL) return;
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);

    }

    // 루트노드가 root 인 이진검색트리를 중위(inorder) 탐색
    void inOrder(Node* p){
        if(root == NULL) return ;
        else{    
            inOrder(p->left);
            cout << p->data << endl;
            cout << p->left << "     " << p->right << endl;
            inOrder(p->right);
        }
    }

    // 루트노드가 root 인 이진검색트리를 후위(postorder) 탐색
    void postOrder(struct Node* p){
        if(root == NULL) return;
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";

    }

    // 루트노드가 root 인 이진검색트리의 모든 노드의 개수를 계산
    int size(struct Node* p){
        int s = 0;
        if(root == NULL) return 1;
        s = size(p->left) + size(p->right) + 1;
        cout << "GET size" << endl;
        return s;
    }

    // 루트노드가 root 인 이진검색트리의 높이를 계산
    int height(struct Node* p){
        int h = 0;
        if(root == NULL) return 1;
        h = max(height(p->left), height(p->right)) + 1;
                cout << "GET height" << endl;

        return h;
    }

    // 루트노드가 root 인 이진검색트리의 모든 노드에 저장된 데이터의 합을 계산
    int sumOfWeight(struct Node* p){
        return 0;
    }

    // 루트노드가 root 인 이진검색트리의 루트노드부터 단말노드까지의 경로 상의 모든 노드에 저 장된 데이터의 합이 가장 큰 합을 계산
    int maxPathWeight(struct nNde* p){
        return 0;
    }

    // 루트노드가 root 인 이진검색트리를 미러 이지미가 되도록 노드의 순서를 변환
    void mirror(struct Node* p){

    }

    // 루트노드가 root 인 이진검색트리의 동적으로 메모리 할당된 노드를 해제하여 이진검색트리 를 소멸
    void destruct(struct Node* p){

    }

};

int main(){
    int t, n, k;
    cin >> t;
    for(int i=0; i<t; i++){
        BinarySearchTree bst;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> k;
            bst.insert(bst.root, k);
        }
        cout << bst.root << endl;
        cout << "VSTDFDKFDK" << bst.root->data << endl;
        bst.inOrder(bst.root);
        cout << bst.size(bst.root) << endl;
        cout << bst.height(bst.root) << endl;
    }
    return 0;
}


// 5 3 4 5 1 2