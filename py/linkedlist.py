class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        print "rytvidu"


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

	def get_position(self, position):
		pos = 0
		if self.head:
			while current.next:
				pos = pos + 1
				if pos = position

		return pos

	def insert(self, new_element, position):
		return None

	def delete(self, pos):
		return None
