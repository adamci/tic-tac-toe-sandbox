#include <vector>


typedef struct node *Node;

struct node {
	char grid[3][3];
	std::vector<struct node *> moves;
	float value;
};

class movesetTree
{
private:
	Node root;
	Node currentMove;

public:
	movesetTree();
};