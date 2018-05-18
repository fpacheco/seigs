import numpy as np
import matplotlib.pyplot as plt
from numpy import genfromtxt

# Delta time 512 Hz
deltat = 1.0/512.0
# COmienzo a leer
LN = 33
# Columnas
c1 = 'NS'
c2 = 'EW'
c3 = 'Z'
c4 = 'TRI'
# Data
dt = list()
d1 = list()
d2 = list()
d3 = list()
d4 = list()
# Number of data previous of trigger
npre = int(512*0.3)
npos = int(512*1.4)

# 
def readCSV(fname):	
	import csv
	acdt = 0
	with open(fname, 'r') as csvfile:
		csvreader = csv.reader(csvfile, delimiter=' ')
		# This skips the first row of the CSV file.
		# csvreader.next() also works in Python 2.
		for sk in range(1,LN):
			next(csvreader)
		for row in csvreader:
			# Time for this data
			acdt = acdt + deltat
			dt.append(acdt)
			d1.append(float(row[0]))
			d2.append(float(row[1]))
			d3.append(float(row[2]))
			d4.append(float(row[3]))

def plotChannels():
	plt.figure(1)
	plt.subplot(221)
	plt.plot(dt, d1, 'r-')
	plt.subplot(222)
	plt.plot(dt, d2, 'g-')
	plt.subplot(223)
	plt.plot(dt, d3, 'b-')
	plt.subplot(224)
	plt.plot(dt, d4, 'y-')
	plt.show()


def triggers():
	tr = list()
	for i in range(len(d4)):
		if d4[i] != 0.000:
			tr.append(i)
	return tr

fname = "EqualizedFile.dat"
readCSV(fname)

ntr = triggers()

def plots(n, prev, post, title="No title"):
	pr = n - prev
	po = n + post
	dt0 = dt[n]
	rdt = list()
	for e in dt[pr:po+1]:
		rdt.append(e-dt0)			

	plt.figure(1)
	
	plt.subplot(311)
	plt.plot(rdt, d1[pr:po+1], 'r-')
	plt.title("%s distancia %s m" % (c1, title))
	plt.grid(True)	
	
	plt.subplot(312)
	plt.plot(rdt, d2[pr:po+1], 'g-')
	plt.title("%s distancia %s m" % (c2, title))
	plt.grid(True)
	
	plt.subplot(313)
	plt.plot(rdt, d3[pr:po+1], 'b-')
	plt.title("%s distancia %s m" % (c3, title))
	plt.grid(True)
	
	plt.show()

c = 0
for n in ntr:	
	c = c + 3
	plots(n, npre, npos, c)
	
	
	 
	


