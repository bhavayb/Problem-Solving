class MyLinkedList {
public:
    int size;

    struct ListNode {
        int data;
        ListNode* next;
        ListNode(int val) {
            data = val;
            next = nullptr;
        }
    };
    ListNode* head;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index > size - 1)
            return -1;
        int cnt = 0;
        ListNode* temp = head;
        while (cnt != index) {
            cnt++;
            temp = temp->next;
        }
        return temp->data;
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        size++;
        return;
    }

    void addAtTail(int val) {
        if (size == 0) {
            ListNode* node = new ListNode(val);
            head = node;
             size++;
            return;
           
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        ListNode* node = new ListNode(val);
        temp->next = node;
        size++;
        return;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        ListNode* node = new ListNode(val);
        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
    if(index >= size) {
        return;
    }
    if(index == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    ListNode* temp = head;
    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    ListNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    size--;
}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */