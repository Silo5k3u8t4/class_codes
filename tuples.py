print("\n1.concatenate\n2.Delete\n3.count of item\n4.length\n5.max\n6.min\n7.sum\n8.exit\n")
tup1=(12,16,12,15,28)
tup2=(24,66,34,3,12)
while True:
	ch=int(input("Enter your choice::"))
	if ch==1:
		tup3=tup1+tup2
		print("The resultant tuple=",tup3)
	elif ch==2:
		c=int(input("Which tuple do you want to delete tup1 or tup2 ::"))
		if c==1:
			del tup1
		else:
			del tup2
	elif ch==3:
		i=int(input("Enter the number::"))
		print("The count of ",i," is ",tup3.count(i))
	elif ch==4:
		print("length= ",len(tup3))
	elif ch==5:
		print("Max value = ",max(tup3))
	elif ch==6:
		print("Min value= ",min(tup3))
	elif ch==7:
		print("Sum of numbers = ",sum(tup3))
	elif ch==8:
		break
	else:
		print("invalid choice")
