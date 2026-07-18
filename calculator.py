import tkinter as tk
calculation=""
def add_to_calculation(symbol):
    global calculation #calculation is going to be a global variable, so that, we can actually manipulate it, inside of the function
    calculation+=str(symbol) #type casting into a string and add it to the calculation string
    text_result.delete(1.0, "end") #we have to specify 1.0 here for the start and the end is specified with the string end, so this is how we delete the whole content of the text result field
    text_result.insert(1.0, calculation) #again 1.0 as the index where we insert the string and the string itself is going to be the calculation so this is quite a simple function
    pass
def evaluate_calculation():
    global calculation
    try:    #because we are going to get error sometimes
        calculation=str(eval(calculation))
           #eval(),the problem with that function is that it is not only for evaluating calculations it can also evaluate python code and the problem with that is of course theoretically someone could inject some
           # code so of course in this case this is a graphical user interface calculator that you're just going to use for fun so you're going to build this project in order to learn graphical user interface programming
           # you're not going to build it and put it online somewhere and connect it to your sensitive files but theoretically just be aware that this is a security issue because people can inject code into your
           # um into your program and then maybe do something with it just keep that in mind that you don't get used to you using the eval function
        text_result.delete(1.0, "end")
        text_result.insert(1.0, calculation)
    except:
        clear_field()
        text_result.insert(1.0, "ERROR")
        pass
def clear_field():
    global calculation
    calculation=""
    text_result.delete(1.0, "end")
    pass
#here we're going to have to build a basic uh window or a basic graphical user interface so that we can
# actually say okay we want to have a text field,and we want to get the values from that text field
# uh we want to clear that text field and so on
root = tk.Tk()
root.geometry("300x275") #the basic stuff like the geometry of the windows, the dimensions
text_result=tk.Text(root,height=2,width=16,font=("Arial",24)) #text field for the result
text_result.grid(columnspan=5) #we're going to use a grid here,and we're going to say column span
btn_1= tk.Button(root,text="1",command=lambda: add_to_calculation(1), width=5,font=("Arial",14) )#the button is going to have a command and as a command we're going to pass a lambda expression and we're going to do that because uh otherwise we would not be able to pass a parameter that easily
# so why do we do it like that why don't we just do it without lambda, the problem with this is that it would immediately call the function whereas lambda just refers to a function that does this if called
btn_1.grid(column=1,row=2)
btn_2= tk.Button(root,text="2",command=lambda: add_to_calculation(2), width=5,font=("Arial",14) )
btn_2.grid(column=2,row=2)
btn_3= tk.Button(root,text="3",command=lambda: add_to_calculation(3), width=5,font=("Arial",14) )
btn_3.grid(column=3,row=2)
btn_4= tk.Button(root,text="4",command=lambda: add_to_calculation(4), width=5,font=("Arial",14) )
btn_4.grid(column=1,row=3)
btn_5= tk.Button(root,text="5",command=lambda: add_to_calculation(5), width=5,font=("Arial",14) )
btn_5.grid(column=2,row=3)
btn_6= tk.Button(root,text="6",command=lambda: add_to_calculation(6), width=5,font=("Arial",14) )
btn_6.grid(column=3,row=3)
btn_7= tk.Button(root,text="7",command=lambda: add_to_calculation(7), width=5,font=("Arial",14) )
btn_7.grid(column=1,row=4)
btn_8= tk.Button(root,text="8",command=lambda: add_to_calculation(8), width=5,font=("Arial",14) )
btn_8.grid(column=2,row=4)
btn_9= tk.Button(root,text="9",command=lambda: add_to_calculation(9), width=5,font=("Arial",14) )
btn_9.grid(column=3,row=4)
btn_0= tk.Button(root,text="0",command=lambda: add_to_calculation(0), width=5,font=("Arial",14) )
btn_0.grid(column=2,row=5)
btn_plus= tk.Button(root,text="+",command=lambda: add_to_calculation("+"), width=5,font=("Arial",14) )
btn_plus.grid(column=4,row=2)
btn_minus= tk.Button(root,text="-",command=lambda: add_to_calculation("-"), width=5,font=("Arial",14) )
btn_minus.grid(column=4,row=3)
btn_mul= tk.Button(root,text="×",command=lambda: add_to_calculation("*"), width=5,font=("Arial",14) )
btn_mul.grid(column=4,row=4)
btn_divide= tk.Button(root,text="÷",command=lambda: add_to_calculation("/"), width=5,font=("Arial",14) )
btn_divide.grid(column=4,row=5)
btn_open= tk.Button(root,text="(",command=lambda: add_to_calculation("("), width=5,font=("Arial",14) )
btn_open.grid(column=1,row=5)
btn_close= tk.Button(root,text=")",command=lambda: add_to_calculation(")"), width=5,font=("Arial",14) )
btn_close.grid(column=3,row=5)
btn_equals= tk.Button(root,text="=",command=evaluate_calculation, width=5,font=("Arial",14) )
btn_equals.grid(column=4,row=6)
btn_dot= tk.Button(root,text=".",command=lambda: add_to_calculation("."), width=5,font=("Arial",14) )
btn_dot.grid(column=2,row=6)
btn_clear= tk.Button(root,text="CLR",command=clear_field, width=5,font=("Arial",14) ) #we do not () 'cause we are not calling the clear function,we are passing it
btn_clear.grid(column=1,row=6)
btn_percent= tk.Button(root,text="%",command=lambda: add_to_calculation("%"), width=5,font=("Arial",14) )
btn_percent.grid(column=3,row=6)
root.mainloop()
