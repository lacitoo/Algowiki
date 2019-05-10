#include <iostream>
#include <cmath>

struct Node {
    Node* zero = nullptr;
    Node* one = nullptr;

    int value = -1;
};

void insert(Node& root, int number, int depth) {
    Node* at = &root;

    for (int k = depth - 1; k >= 0; k--) {
        int bit = ((number >> k) & 1);

        if (bit == 0) {
            if (at->zero == nullptr) {
                at = at->zero = new Node();
            } else {
                at = at->zero;
            }
        } else {
            if (at->one == nullptr) {
                at = at->one = new Node();
            } else {
                at = at->one;
            }
        }
    }

    at->value = number;
}

int highestXOR(Node& root, int number, int depth) {
    Node* at = &root;

    for (int k = depth - 1; k >= 0; k--) {
        int bit = ((number >> k) & 1);

        if (bit == 0) {
            if (at->one != nullptr) {
                at = at->one;
            } else {
                at = at->zero;
            }
        } else {
            if (at->zero != nullptr) {
                at = at->zero;
            } else {
                at = at->one;
            }
        }
    }

    return at->value;
}

int main() {
    int l, r;

    std::cin >> l >> r;
    int depth = std::ceil(std::log2(r));

    Node root;

    insert(root, l, depth);

    int maxVal = 0;
    for (int i = l + 1; i <= r; i++) {
        int highest = highestXOR(root, i, depth);

        if ((i ^ highest) > maxVal) {
            maxVal = i ^ highest;
        }

        insert(root, i, depth);
    }

    std::cout << maxVal << std::endl;

    return 0;
}