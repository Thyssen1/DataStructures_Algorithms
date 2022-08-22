#include <iostream>

struct Node {
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BST {
private:
	// Private attributes
	Node* m_root;	// Pointer to root node
	int m_entries;	// Number of entries

	// Private methods
	Node* m_insert(Node* currentNode, int data);
	Node* m_remove(Node* currentNode, int data);

	Node* m_delete(Node* currentNode);

	void m_preorder(Node* currentNode) const;
	void m_inorder(Node* currentNode) const;
	void m_postorder(Node* currentNode) const;
	
	Node* m_fmin(Node* currentNode);
	Node* m_fmax(Node* currentNode);

public:
	BST();
	~BST();

	int size() const;
	bool empty() const;

	void insert(int data);
	void remove(int data);
	void preorder() const;
	void inorder() const;
	void postorder() const;
};

Node* BST::m_insert(Node* currentNode, int val) {
	// Check if root (current node) is empty
	if (currentNode == nullptr) { 
		std::cout << "Created new Node with value: " << val << "\n";
		currentNode = new Node();
		currentNode->data = val;
		currentNode->left = nullptr;
		currentNode->right = nullptr;
	}
	else if (val > currentNode->data) {
		currentNode->right = m_insert(currentNode->right, val);
	}
	else if (val < currentNode->data) {
		currentNode->left = m_insert(currentNode->left, val);
	}

	return currentNode;
}

Node* BST::m_remove(Node* currentNode, int val) {
	Node* temp = nullptr;
	if (currentNode == nullptr) {
		return nullptr;
	}
	else if (val > currentNode->data) {
		// Search for larger value
		currentNode->right = m_remove(currentNode->right, val);
	}
	else if (val < currentNode->data) {
		// Search for smaller value
		currentNode->left = m_remove(currentNode->left, val);
	}
	else {
		if (currentNode->left && currentNode->right) {
			// Locate minimum to the right and use as replacement
			Node* temp = m_fmin(currentNode->right);
			currentNode->data = temp->data;
			currentNode->right = m_remove(currentNode->right, currentNode->data);
		}
		else {
			Node* temp = currentNode;
			if (currentNode->left == nullptr) {
				currentNode = currentNode->right;
			}
			else if (currentNode->right == nullptr) {
				currentNode = currentNode->left;
			}
			delete temp;
			temp = nullptr;
		}
	}

	return currentNode;
}

Node* BST::m_delete(Node* currentNode) {
	if (currentNode == nullptr) { return nullptr; }

	m_delete(currentNode->left);
	m_delete(currentNode->right);
	std::cout << "Deleted node with value: " << currentNode->data << "\n";
	delete currentNode;
	currentNode = nullptr;

	return nullptr;
}

BST::~BST() {
	m_root = m_delete(m_root);
}

void BST::m_preorder(Node* currentNode) const {
	if (currentNode == nullptr) { return; }

	std::cout << currentNode->data << " ";
	m_preorder(currentNode->left);
	m_preorder(currentNode->right);
}

void BST::m_inorder(Node* currentNode) const {
	if (currentNode == nullptr) { return; }

	m_inorder(currentNode->left);
	std::cout << currentNode->data << " ";
	m_inorder(currentNode->right);
}

void BST::m_postorder(Node* currentNode) const {
	if (currentNode == nullptr) { return; }

	m_postorder(currentNode->left);
	m_postorder(currentNode->right);
	std::cout << currentNode->data << " ";
}

Node* BST::m_fmin(Node* currentNode) {
	if (currentNode == nullptr) { return nullptr; } 
	if (currentNode->left == nullptr) { return currentNode; }
	return m_fmin(currentNode->left);
}

Node* BST::m_fmax(Node* currentNode) {
	if (currentNode == nullptr) { return nullptr; }
	if (currentNode->right == nullptr) { return currentNode; }
	return m_fmax(currentNode->right);
}


int BST::size() const {
	return m_entries;
}

bool BST::empty() const {
	return m_root == nullptr;
}

BST::BST()
	: m_root(nullptr), m_entries(0) {}

void BST::insert(int data) {
	m_root = m_insert(this->m_root, data);
}

void BST::remove(int data) {
	m_remove(m_root, data);
}

void BST::preorder() const {
	m_preorder(m_root);
	std::cout << "\n";
}

void BST::inorder() const {
	m_inorder(m_root);
	std::cout << "\n";
}

void BST::postorder() const {
	m_postorder(m_root);
	std::cout << "\n";
}

int main() {
	BST b;
	
	std::cout << "Is the binary search tree empty? " << b.empty() << "\n";

	b.insert(20);
	b.insert(25);
	b.insert(15);
	b.insert(10);

	std::cout << "Is the binary search tree empty? " << b.empty() << "\n";

	// Print in order
	b.inorder();

	b.remove(10);

	// Print in order
	b.inorder();

	std::cout << "Print pre order: \n";
	b.preorder();

	std::cout << "Print post order: \n";
	b.postorder();

	return 0;
}