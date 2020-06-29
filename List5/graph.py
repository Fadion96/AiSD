import matplotlib.pyplot as plt

with open("select_stat.txt", "r") as f:
    select = f.read()
with open("randomselect_stat.txt", "r") as f:
    randselect = f.read()
with open("tree_os_stat.txt", "r") as f:
    osselect = f.read()

select = select.split('\n')
select.pop()
randselect = randselect.split('\n')
randselect.pop()
osselect = osselect.split('\n')
osselect.pop()
x = [row.split(" ")[0] for row in select]
mins = [row.split(" ")[1] for row in select]
avgs = [row.split(" ")[2] for row in select]
maxs = [row.split(" ")[3] for row in select]
minrs = [row.split(" ")[1] for row in randselect]
avgrs = [row.split(" ")[2] for row in randselect]
maxrs = [row.split(" ")[3] for row in randselect]
minos = [row.split(" ")[1] for row in osselect]
avgos = [row.split(" ")[2] for row in osselect]
maxos = [row.split(" ")[3] for row in osselect]

plt.figure(1)
line1, = plt.plot(x, mins, "or", label='min select', markersize=1)
line2, = plt.plot(x, avgs, "oy", label='avg select', markersize=1)
line3, = plt.plot(x, maxs, "og", label='max select', markersize=1)
line5, = plt.plot(x, avgrs, "om", label='avg randselect', markersize=1)
line6, = plt.plot(x, maxrs, "oc", label='max randselect', markersize=1)
line7, = plt.plot(x, minos, "ow", label='min osselect', markersize=1)
line8, = plt.plot(x, avgos, "ob", label='avg osselect', markersize=1)
line9, = plt.plot(x, maxos, "ok", label='max osselect', markersize=1)
plt.legend(handles=[line1, line2, line3, line5, line6, line7, line8, line9])
plt.title('Comparison of selects by compares ')
plt.xlabel('Number of elements')
plt.ylabel('Number of compares')
plt.grid(True)

plt.figure(2)
line7, = plt.plot(x, minos, "or", label='min osselect', markersize=1)
line8, = plt.plot(x, avgos, "oy", label='avg osselect', markersize=1)
line9, = plt.plot(x, maxos, "og", label='max osselect', markersize=1)
plt.legend(handles=[line7, line8, line9])
plt.title('Number of compares in osselect algorithm')
plt.xlabel('Number of elements')
plt.ylabel('Number of compares')
plt.grid(True)

plt.show()