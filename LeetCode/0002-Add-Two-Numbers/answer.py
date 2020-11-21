class Solution:
    def listToNum(self, ln: ListNode):
        num = 0
        mul = 1
        
        while(ln != None):
            num += ln.val * mul
            mul *= 10
            ln = ln.next
        
        return num
    
    def numToList(self, numList):
        First = ListNode(numList.pop(), None)
        Cur = First
        Next = None
        
        while(numList):
            Next = ListNode(numList.pop(), None)
            Cur.next = Next
            Cur = Next
            Next = None
        
        return First
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = self.listToNum(l1)
        num2 = self.listToNum(l2)
        sumOfNums = num1 + num2
        l = [] 
        l[:] = str(sumOfNums)
        
        return self.numToList(l)
