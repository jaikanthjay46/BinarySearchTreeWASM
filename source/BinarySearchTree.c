#include<stdio.h>
#include<stdlib.h>
#include <emscripten.h>

typedef struct node{
	struct node * l, * r;
	int value;
} node;

node* rt = NULL;

// [ left, visit, right ] 

void inR(node * n){
	if(n->l != NULL) inR(n->l);
	printf("%d ", n->value);
	if(n->r != NULL) inR(n->r);
}
EMSCRIPTEN_KEEPALIVE
void in () { 
	inR(rt); 
}
// [ visit, left, right ]
EMSCRIPTEN_KEEPALIVE

void preR(node * n){
	printf("%d ", n->value);
	if(n->l) preR(n->l);
	if(n->r) preR(n->r);
}
void pre() { preR(rt); }
// [ left, right, visit ]

void postR(node * n){
	if(n->l) postR(n->l);
	if(n->r) postR(n->r);
	printf("%d ", n->value);
}
EMSCRIPTEN_KEEPALIVE
void post() { postR(rt); } 
// create a new node & set default nodes
EMSCRIPTEN_KEEPALIVE
node * newnode(int value){
	node * n = malloc(sizeof(node));
	n->value = value;
	n->l = NULL;
	n->r = NULL;
	return n;
}

// recursive insertion from the tree root
EMSCRIPTEN_KEEPALIVE
void insertR(node ** root, node * child){
	//printf("Value of child = %d", child->value);
	if(*root == NULL) *root = child;  // tree root not exists
	
	else insertR( child->value <= (*root)->value ? &((*root)->l) : &((*root)->r) , child );  // recursive call
}
EMSCRIPTEN_KEEPALIVE
void insert(int val){
	node* tmp = newnode(val);
	//printf("The value to be inserted is %d, tmp val is %d\n",val,tmp->value);
	insertR(&rt,tmp);
	//in(rt);
}
EMSCRIPTEN_KEEPALIVE
// recursive search of a node
node * searchR(node * root, int value){
	return (root==NULL) ? NULL : root->value == value ? root : searchR( value > root->value ? root->r : root->l , value );
}
EMSCRIPTEN_KEEPALIVE
unsigned int search(int v){
	if(searchR(rt,v)){
//		printf("present\n");
		return 1;
	} else {
		return 0;
		//in(rt);
//		printf("not present\n");
	}
}




int main() {
return 0;
}

