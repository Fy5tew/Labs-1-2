#include <string>
#include <sstream>


template <typename T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data, BinaryTreeNode<T>* left = nullptr, BinaryTreeNode<T>* right = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
	}

	void insert(T value) {
		if (value < data) {
			if (left) {
				return left->insert(value);
			}
			left = new BinaryTreeNode<T>(value);
		}
		else {
			if (right) {
				return right->insert(value);
			}
			right = new BinaryTreeNode<T>(value);
		}
	}

	void remove(T value) {
		if ((left && value != left->data) && (right && value != right->data)) {
			return (value < data)? left->remove(value) : right->remove(value);
		}

		BinaryTreeNode<T>* child_node = nullptr;
		BinaryTreeNode<T>** change_node_pointer = nullptr;

		if (value == left->data) {
			child_node = left;
			change_node_pointer = &left;
		}
		else if (value == right->data) {
			child_node = right;
			change_node_pointer = &right;
		}

		if (!child_node->left && !child_node->right) {
			*change_node_pointer = nullptr;
		}
		else if (!child_node->left) {
			*change_node_pointer = child_node->right;
		}
		else if (!child_node->right) {
			*change_node_pointer = child_node->left;
		}
		else {
			return;
		}

		delete child_node;
	}

	void clear() {
		if (left) {
			left->clear();
		}
		if (right) {
			right->clear();
		}
		delete this;
	}
};


template <typename T>
class BinaryTree {
private:
	BinaryTreeNode<T>* head = nullptr;

public:
	bool isEmpty() {
		return head == nullptr;
	}

	std::string toString() {
		std::stringstream buffer;

		toString(head, -1, buffer);

		return buffer.str();
	}

	size_t getSize() {
		return 0;
	}

	void insert(T value) {
		if (isEmpty()) {
			head = new BinaryTreeNode<T>(value, nullptr, nullptr);
		}
		else {
			head->insert(value);
		}
	}

	void remove(T value) {
		head->remove(value);
	}

	void clear() {
		head->clear();
		head = nullptr;
	}

private:
	void toString(BinaryTreeNode<T>* t, int u, std::stringstream& buffer) {
		if (t == nullptr)  return;
		else
		{
			toString(t->left, ++u, buffer);
			for (int i = 0; i < u; ++i)
				buffer << "|";
			buffer << t->data << "\n";
			u--;
		}
		toString(t->right, ++u, buffer);
	}
};
