class color:
	PURPLE = '\033[95m'
	CYAN = '\033[96m'
	DARKCYAN = '\033[36m'
	BLUE = '\033[94m'
	GREEN = '\033[92m'
	YELLOW = '\033[93m'
	RED = '\033[91m'
	BOLD = '\033[1m'
	UNDERLINE = '\033[4m'
	END = '\033[0m'

with open('files/input.txt') as f:
	lines = f.readlines()

temp = 0
total = []
calories = 0

for line in lines:
	line = line.strip('\n')
	if line != '':
		temp += int(line)
	else:
		total.append(temp)
		temp = 0
total.sort(reverse=True);

print(color.GREEN + color.BOLD + 'Total calories part 1: '+ str(total[0]))
print(color.GREEN + color.BOLD + 'Total calories part 2: '+ str(total[0] + total[1] + total[2]))