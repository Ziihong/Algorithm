#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = 0;
		right = 0;
	}
};

    // 루트노드가 root 인 이진검색트리에 데이터 data 를 입력하는 함수.
    void insert(Node** p, int data){
        if(*p == NULL){
            Node* q = new Node(data); // node 생성
            *p = q;
        } 
        else if(data < (*p)->data){
            insert(&(*p)->left, data);
        }
        else if(data > (*p)->data){
            insert(&(*p)->right, data);
        }
    }


    // 루트노드가 root 인 이진검색트리를 전위(preorder) 탐색
    void preOrder(Node* p){
        if(p != NULL){
            cout << p->data << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    // 루트노드가 root 인 이진검색트리를 중위(inorder) 탐색
    void inOrder(Node* p){
        if(p != NULL){    
            inOrder(p->left);
            cout << p->data << " ";
            inOrder(p->right);
        }
    }

    // 루트노드가 root 인 이진검색트리를 후위(postorder) 탐색
    void postOrder(Node* p){
        if(p != NULL){
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << " ";
        }
    }

    // 루트노드가 root 인 이진검색트리의 모든 노드의 개수를 계산
    int size(Node* p){
        if(p == NULL) return 0;
        
        int s = size(p->left) + size(p->right) + 1;
        return s;
    }

    // 루트노드가 root 인 이진검색트리의 높이를 계산
    int height(Node* p){
        if(p == NULL) return 0;

        int h = max(height(p->left), height(p->right)) + 1; 
        return h;
    }

    // 루트노드가 root 인 이진검색트리의 모든 노드에 저장된 데이터의 합을 계산
    int sumOfWeight(Node* p){
        if(p == NULL) return 0;
        
        int sum = p->data + sumOfWeight(p->left) + sumOfWeight(p->right);
        return sum;
    }

    // 루트노드가 root 인 이진검색트리의 루트노드부터 단말노드까지의 경로 상의 모든 노드에 저 장된 데이터의 합이 가장 큰 합을 계산
    int maxPathWeight(Node* p){
        if(p == NULL) return 0;
        
        int left_sum, right_sum, max_sum;
        left_sum = p->data + maxPathWeight(p->left);
        right_sum = p->data + maxPathWeight(p->right);

        return max(left_sum, right_sum);
    }

    // 루트노드가 root 인 이진검색트리를 미러 이지미가 되도록 노드의 순서를 변환
    void mirror(Node** p){
        if(p == NULL) return ;

        if((*p)->left) mirror(&(*p)->left);
        if((*p)->right) mirror(&(*p)->right);

        // swap
        Node* tmp = (*p)->left;
        (*p)->left = (*p)->right;
        (*p)->right = tmp;
    }

    // 루트노드가 root 인 이진검색트리의 동적으로 메모리 할당된 노드를 해제하여 이진검색트리를 소멸
    void destruct(Node** p){        
        if((*p)->left) destruct(&(*p)->left);
        if((*p)->right) destruct(&(*p)->right);

        (*p)->left = NULL;
        (*p)->right = NULL;

        if(*p != NULL) {
            delete *p;
            *p = NULL;
        }
    }
    

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, key;
    cin >> t;


    for(int i=0; i<t; i++){
        cin >> n;
        
        Node *root = NULL;

        for(int j=0; j<n; j++){
            cin >> key;
            insert(&root, key);
        }
        cout << size(root) << '\n';
        cout << height(root) - 1<< '\n';
        cout << sumOfWeight(root) << '\n';
        cout << maxPathWeight(root) << '\n';
        mirror(&root);
        preOrder(root);
        cout << '\n';
        inOrder(root);
        cout << '\n';
        postOrder(root);
        cout << '\n';
        destruct(&root);

        if(root != NULL){
            delete root;
            root = NULL;
        }

        if(root == NULL) cout <<  0 << '\n';
        else cout << 1 << '\n';
    }
        
    return 0;
}
