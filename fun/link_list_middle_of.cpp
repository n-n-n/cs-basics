/**
    struct
    {
 *     int val;
 *     Node *next;
 *     Node(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    Node* middleNode(Node* head) {
        if (!head) return head;
        Node* p1 = head;
        Node* p2 = head;
       
        while(p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
};
