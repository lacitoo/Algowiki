from sys import stdin,stdout
 
def DFS(prevNode,currNode):
   
    global visited
    global nodeBlock
    global node
   
    visited[currNode] = True
 
    stdout.write("{} ".format(currNode+1))
   
    for othNode in nodeBlock[currNode]:
       
        if not othNode==prevNode and not visited[othNode]:
            DFS(currNode,othNode)
               
        elif not othNode==prevNode:
 
            nodeBlock[currNode].remove(othNode)
            nodeBlock[othNode].remove(currNode)
 
            stdout.write("{} ".format(othNode+1))
            stdout.write("{} ".format(currNode+1))
   
    node.append(currNode + 1)
       
 
inputNumber= list(map(int,stdin.readline().split(" ")))
crossRoadNum = inputNumber[0]
streetNum = inputNumber[1]
 
nodeBlock = []
for i in range(0, crossRoadNum):
    nodeBlock.append([])
 
visited = []
for i in range(0,crossRoadNum):
    visited.append(False)
   
node = []
 
for i in range(streetNum):
    inputNumber = list(map(int,stdin.readline().split(" ")))
    a = inputNumber[0] - 1
    b = inputNumber[1] - 1
   
    nodeBlock[a].append(b)
    nodeBlock[b].append(a)
 
DFS(0,0)
for currentNode in node[1:]:
    stdout.write("{} ".format(currentNode))