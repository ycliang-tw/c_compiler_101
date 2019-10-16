/***************************************
 *
 *	expr = mul ( "+" mul | "-" mul)*
 *	mul = term ( "*" term | "/" term)*
 *	term = num | "(" expr ")"
 *
 **************************************/

#ifndef __EBNF_NODE_H__
#define __EBNF_NODE_H__
typedef enum{
	ND_ADD,	// +
	ND_SUB,	// -
	ND_MUL,	// *
	ND_DIV, // /
	ND_NUM, // integer
} NodeKind;

typedef struct Node Node;

struct Node{
	NodeKind kind;	// type of the node
	Node *lhs;		// left
	Node *rhs;		// right
	int val;		// when kind == ND_NUM
};

Node *new_node(NodeKind kind, Node *lhs, Node *rhs){
	Node *node = (Node*)calloc(1, sizeof(Node));
	node->kind = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return node;
}

Node *new_node_num(int val){
	Node *node = (Node*)calloc(1, sizeof(Node));
	node->kind = ND_NUM;
	node->val = val;
	return node;
}

Node *expr();

#endif
