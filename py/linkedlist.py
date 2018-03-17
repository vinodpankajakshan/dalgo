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
		return None

	def delete(self, pos):
		return None

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













