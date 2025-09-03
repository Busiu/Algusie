package datastructures.segmenttrees;

// Solution for https://leetcode.com/problems/count-integers-in-intervals/description/
public class DynamicSegmentTree {
    static class Node {
        Node left;
        Node right;
        int val;
        Node() {this.val = 0;}
    }

    Node root;

    DynamicSegmentTree() {
        this.root = new Node();
    }

    void setToOne(Node node, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return;
        if (tl >= l && tr <= r) {
            node.val = tr - tl + 1;
            return;
        }

        // Children creation only when tl != tr???
        if (tl != tr) {
            if (node.left == null) node.left = new Node();
            if (node.right == null) node.right = new Node();
        }

        int tm = (tl + tr) / 2;
        setToOne(node.left, tl, tm, l, r);
        setToOne(node.right, tm + 1, tr, l, r);
        if (node.val != tr - tl + 1) {
            node.val = node.left.val + node.right.val;
        }
    }

    int getAll() {
        return root.val;
    }
}
