def singlesExists(singles):
	for s in singles:
		if(s == 1):
			return True
	return False

def nextSingle(singles):
	for i, s in enumerate(singles):
		if(s == 1):
			return i

def isMatch(womanList, married, pretendant):
	if(married == -1):
		return True
	else:
		for man in womanList:
			if man == married :
				return False
			elif man == pretendant:
				return True

def printCouples(couples):
	for couple in couples:
		print(str(couple[0]+1) + " " + str(couple[1]+1))

# Reading number of test cases input
testCases = int(input()) 

for i in range(testCases):
	# Initialize Men and Women preferences and couples as empty arrays
	w = []
	m = []
	couples = []

	# Reading the size of the preference array
	n = int(input()) 

	# Singles array for men; Married array for women hold the man index
	singles = [1] * n
	married = [-1] * n

	# Read and parses man and woman preference arrays
	for _ in range(n):
		womanInput = input().split(" ")[1:]
		w.append([int(x)-1 for x in womanInput])
	for _ in range(n):
		manInput = input().split(" ")[1:]
		m.append([int(x)-1 for x in manInput])

	while(singlesExists(singles)):
		nextMan = nextSingle(singles)
		for woman in m[nextMan]:
			if isMatch(w[woman], married[woman], nextMan):
				newSingle = married[woman]
				married[woman] = nextMan
				singles[nextMan] = 0
				couples.append([nextMan, woman])
				if(newSingle != -1):
					couples.remove([newSingle, woman])
					singles[newSingle] = 1
				break
	

	printCouples(couples)
