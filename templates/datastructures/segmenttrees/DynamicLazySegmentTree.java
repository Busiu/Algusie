package datastructures.segmenttrees;

// Solution for https://leetcode.com/problems/count-integers-in-intervals/description/
public class DynamicLazySegmentTree {
    static class Node {
        Node left;
        Node right;
        int tl;
        int tr;
        int val;
        int lazy;
        Node(int tl, int tr) {
            this.tl = tl;
            this.tr = tr;
            this.val = 0;
            this.lazy = 0;
        }
    }

    Node root;

    DynamicLazySegmentTree() {
        this.root = new Node(1, 1_000_000_000);
    }

    void push(Node node) {
        if (node.lazy != 0) {
            node.val = node.lazy;
            if (node.tl != node.tr) {
                node.left.lazy = node.left.tr - node.left.tl + 1;
                node.right.lazy = node.right.tr - node.right.tl + 1;
            }
            node.lazy = 0;
        }
    }

    void createChildrenIfAbsent(Node node) {
        if (node.tl != node.tr) {
            int tm = (node.tl + node.tr) / 2;
            if (node.left == null) node.left = new Node(node.tl, tm);
            if (node.right == null) node.right = new Node(tm + 1, node.tr);
        }
    }

    void setToOne(Node node, int l, int r) {
        createChildrenIfAbsent(node);
        push(node);

        if (node.tl > r || node.tr < l) return;
        if (node.tl >= l && node.tr <= r) {
            node.lazy = node.tr - node.tl + 1;
            push(node);
        } else {
            setToOne(node.left, l, r);
            setToOne(node.right, l, r);
            node.val = node.left.val + node.right.val;
        }
    }

    int getAll() {
        return root.val;
    }
}
