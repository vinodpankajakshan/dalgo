class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList(object):
    def __init__(self, head=None):
        self.head = head

    def append(self, new_element):
        current = self.head

        if self.head:
            while current.next:
                current = current.next
            current.next = new_element
        else:
            self.head = new_element

    def insert_first(self, new_element):
        new_element.next = self.head
        self.head = new_element
            
    def delete_first(self):
        """
        Delete the first element in the LinkedList

        ensuring that the deleted element doesn't point to the next element
        https://gist.github.com/adarsh0806/02d8e1d54d510294e75dfbc0d9bd7059
        """
        deleted = self.head

        if self.head:
            self.head = self.head.next
            deleted.next = None

        return deleted


class Stack(object):
    def __init__(self, top=None):
        self.ll = LinkedList(top)

    def push(self, new_element):
        self.ll.insert_first(new_element)

    def pop(self):
        '''Pop the top element'''
        return self.ll.delete_first()












