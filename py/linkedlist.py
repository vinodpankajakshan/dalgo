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

    def insert(self, new_element, position):
        element_prev = self.get_position(position - 1)

        if element_prev:
            new_element.next = element_prev.next
            element_prev.next = new_element

    def delete(self, position):
        pos = 1
        current = self.head
        previous = None

        while current.next and pos != position:
            previous = current
            current = current.next
            pos = pos + 1

        if previous:
            previous.next = current.next
            current = None
        elif current.next and pos == position:
            self.head = self.head.next
        elif pos == position:
            self.head = None
            
    def get_position(self, position):
        pos = 1
        current = self.head

        if self.head:
            while current.next and pos != position:
                pos = pos + 1
                current = current.next

            if pos == position:
                return current

        return None













