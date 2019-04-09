'''
This is the interface that allows for creating nestedIterator
you should not implement it, or speculate about its implementation
'''
class NestedIngeter(object):
    def isInteger(self):
        '''
        @return True if this NestedIngeter holds a single integer,
        rathen than a nested list.
        :rtype bool
        '''

    def getInteger(self):
        '''
        @return the single integer tha this NestedIngeter holds if it
        holds a single integer
        Return None if this NestedIngeter holds a nested list
        :rtype int
        '''

    def getList(self):
        '''
        @return the nested list that this NestedIngeter holds, if it holds
        a nested list
        Return None if this NestedIngeter holds a single integer
        :rtype List[NestedIngeter]
        '''

# 下面是真正我们要写的
class nestedIterator(object):
    def __init__(self, nestedList):
        '''
        Initialize your data structure here
        :type nestedList: List[NestedIngeter]
        '''
        self.stack = nestedList[::]

    def next(self):
        '''
        :rtype: int
        '''
        return self.stack.pop(0).getInteger()

    def hasNext(object):
        '''
        :rtype: bool
        '''
        while self.stack:
            top = self.stack[0]
            if top.isInteger(): return True
            self.stack = top.getList() + self.stack[1:]
        return False
