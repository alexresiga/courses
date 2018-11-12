from tkinter import *
from domain.Book import Book
from domain.Client import Client
from domain.Rental import Rental
from tkinter import messagebox


class GUI:
    def __init__(self, master, controller1, controller2, controller3, controller4):
        self.__Bcontroller = controller1
        self.__Ccontroller = controller2
        self.__Rcontroller = controller3
        self.__Ucontroller = controller4
        self.master = master
        self.start()

    def start(self):
        frame = Frame(self.master, width=420)
        frame.pack_propagate(0)
        frame.pack()
        self.master.title("BOOK RENTALS MANAGEMENT APPLICATION")
        try:

            buton1 = Button(self.master, text="Add new book", width=42)
            buton1.bind("<Button-1>", self.add_book)
            buton1.pack(side=TOP)

            buton6 = Button(self.master, text="Remove book", width=42)
            buton6.bind("<Button-1>", self.remove_book)
            buton6.pack(side=TOP)

            buton8 = Button(self.master, text="Update book", width=42)
            buton8.bind("<Button-1>", self.update_book)
            buton8.pack(side=TOP)

            buton2 = Button(self.master, text="add new client", width=42)
            buton2.bind("<Button-1>", self.add_client)
            buton2.pack(side=TOP)

            buton7 = Button(self.master, text="Remove client", width=42)
            buton7.bind("<Button-1>", self.remove_client)
            buton7.pack(side=TOP)

            buton9 = Button(self.master, text="Update client", width=42)
            buton9.bind("<Button-1>", self.update_client)
            buton9.pack(side=TOP)

            buton3 = Button(self.master, text="list all books", width=42)
            buton3.bind("<Button-1>", self.list_books)
            buton3.pack(side=TOP)

            buton4 = Button(self.master, text="list clients", width=42)
            buton4.bind("<Button-1>", self.list_clients)
            buton4.pack(side=TOP)

            buton10 = Button(self.master, text="add rental", width=42)
            buton10.bind("<Button-1>", self.add_rental)
            buton10.pack(side=TOP)

            buton5 = Button(self.master, text="list rentals", width=42)
            buton5.bind("<Button-1>", self.list_rentals)
            buton5.pack(side=TOP)

            buton11 = Button(self.master, text="return book", width=42)
            buton11.bind("<Button-1>", self.return_book)
            buton11.pack(side=TOP)

            buton12 = Button(self.master, text="search book", width=42)
            buton12.bind("<Button-1>", self.search_book)
            buton12.pack(side=TOP)

            buton13 = Button(self.master, text="search client", width=42)
            buton13.bind("<Button-1>", self.search_client)
            buton13.pack(side=TOP)

            buton14 = Button(self.master, text="Most rented books", width=42)
            buton14.bind("<Button-1>", self.most_rentedBooks)
            buton14.pack(side=TOP)

            buton15 = Button(self.master, text="Most active clients", width=42)
            buton15.bind("<Button-1>", self.most_active)
            buton15.pack(side=TOP)

            buton16 = Button(self.master, text="Most rented authors", width=42)
            buton16.bind("<Button-1>", self.most_rentedAut)
            buton16.pack(side=TOP)

            buton17 = Button(self.master, text="late rentals", width=42)
            buton17.bind("<Button-1>", self.late_rentals)
            buton17.pack(side=TOP)

            buton18 = Button(self.master, text="undo", width=42)
            buton18.bind("<Button-1>", self.undo)
            buton18.pack(side=TOP)

            buton19 = Button(self.master, text="redo", width=42)
            buton19.bind("<Button-1>", self.redo)
            buton19.pack(side=TOP)

            button = Button(self.master, text="QUIT", fg="red", command=self.master.quit, width=42)
            button.pack(side=BOTTOM)
        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master, width=420, height=420)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def both(self, ID, title, desc, author):
        try:
            self.__Ucontroller.newOperation()
            self.__Bcontroller.addBook(Book.create_book(int(ID.get()), title.get(), desc.get(), author.get()))
            messagebox.showinfo("INFO", "BOOK ADDED")
        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def add_book(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter book ID:")
        label.pack()
        ID = Entry(window)
        ID.pack()
        ID.focus_set()
        label2 = Label(window, text="enter title:")
        label2.pack()
        title = Entry(window)
        title.pack()
        label3 = Label(window, text="enter author:")
        label3.pack()
        author = Entry(window)
        author.pack()
        label4 = Label(window, text="enter description:")
        label4.pack()
        desc = Entry(window)
        desc.pack()
        buton = Button(window, text="enter book", command=lambda: self.both(ID, title, desc, author))
        buton.pack()

    def both_remove(self, ID):
        try:
            self.__Ucontroller.newOperation()
            self.__Bcontroller.removeBook(int(ID.get()))
            messagebox.showinfo("INFO", "BOOK REMOVED")
        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def remove_book(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter book ID to be removed:")
        label.pack()
        ID = Entry(window)
        ID.pack()
        ID.focus_set()
        buton = Button(window, text="remove book", command=lambda: self.both_remove(ID))

        buton.pack()

    def both_add(self, ID, name):
        try:
            self.__Ucontroller.newOperation()
            self.__Ccontroller.addClient(Client.create_client(int(ID.get()), name.get()))
            messagebox.showinfo("INFO", "CLIENT ADDED")
        except Exception as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def add_client(self, event):
        altwindow = Toplevel(self.master, width=420, height=420)
        altwindow.pack_propagate(0)
        label = Label(altwindow, text="Enter client ID:")
        label.pack()
        ID = Entry(altwindow)
        ID.pack()
        ID.focus_set()
        label2 = Label(altwindow, text="enter client:")
        label2.pack()
        name = Entry(altwindow)
        name.pack()
        buton = Button(altwindow, text="enter client", command=lambda: self.both_add(ID, name))
        buton.pack()

    def client_both_remove(self, ID):
        try:
            self.__Ucontroller.newOperation()
            self.__Ccontroller.removeClient(int(ID.get()))
            messagebox.showinfo("INFO", "CLIENT REMOVED")

        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def remove_client(self, event):
        altwindow = Toplevel(self.master, width=420, height=420)
        altwindow.pack_propagate(0)
        label = Label(altwindow, text="Enter client ID:")
        label.pack()
        ID = Entry(altwindow)
        ID.pack()
        ID.focus_set()
        buton = Button(altwindow, text="Remove client", command=lambda: self.client_both_remove(ID))
        buton.pack()

    def both_update_book(self, ID, title, desc, author):
        try:
            self.__Ucontroller.newOperation()
            self.__Bcontroller.updateBook(Book.create_book(int(ID.get()), title.get(), desc.get(), author.get()))
            messagebox.showinfo("INFO", "BOOK UPDATED")

        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def update_book(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter book ID to be updated:")
        label.pack()
        ID = Entry(window)
        ID.pack()
        ID.focus_set()
        label2 = Label(window, text="enter new title:")
        label2.pack()
        title = Entry(window)
        title.pack()
        label3 = Label(window, text="enter new author:")
        label3.pack()
        author = Entry(window)
        author.pack()
        label4 = Label(window, text="enter new description:")
        label4.pack()
        desc = Entry(window)
        desc.pack()
        buton = Button(window, text="Update book", command=lambda: self.both_update_book(ID, title, desc, author))
        buton.pack()

    def both_update_client(self, ID, name):
        try:
            self.__Ucontroller.newOperation()
            self.__Ccontroller.updateClient(Client.create_client(int(ID.get()), name.get()))
            messagebox.showinfo("INFO", "CLIENT UPDATED")
        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def update_client(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="Enter client ID:")
        label.pack()
        ID = Entry(window)
        ID.pack()
        ID.focus_set()
        label2 = Label(window, text="enter client:")
        label2.pack()
        name = Entry(window)
        name.pack()
        buton = Button(window, text="enter client", command=lambda: self.both_update_client(ID, name))
        buton.pack()

    def list_books(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=500, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Bcontroller.getAllBooks():
            listbox.insert(END, x)

    def list_clients(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)

        for x in self.__Ccontroller.getAllClients():
            v = StringVar()
            v.set(x)
            label = Label(window, textvariable=v)
            label.pack()

    def list_rentals(self, event):
        window = Toplevel(self.master, width=700, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=700, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Rcontroller.getAllRental():
            listbox.insert(END, x)

    def both_add_rental(self, BID, CID, input_day, input_month):
        try:
            self.__Ucontroller.newOperation()
            self.__Rcontroller.addRental(Rental.create_rental(int(BID.get()), int(CID.get()), int(input_day.get()), int(input_month.get())))
            messagebox.showinfo("INFO", "RENTAL ADDED\n" + str(Rental.create_rental(int(BID.get()), int(CID.get()), int(input_day.get()), int(input_month.get()))))

        except Exception as exc:
            print(str(exc))
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def add_rental(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter book ID:")
        label.pack()
        BID = Entry(window)
        BID.pack()
        BID.focus_set()
        label2 = Label(window, text="enter client ID:")
        label2.pack()
        CID = Entry(window)
        CID.pack()
        label3 = Label(window, text="enter rental day:")
        label3.pack()
        input_day = Entry(window)
        input_day.pack()
        label4 = Label(window, text="enter rental month:")
        label4.pack()
        input_month = Entry(window)
        input_month.pack()
        buton = Button(window, text="Add rental", command=lambda: self.both_add_rental(BID, CID, input_day, input_month))
        buton.pack()

    def both_return(self, ID):
        try:
            self.__Rcontroller.returnBook(int(ID.get()))
            messagebox.showinfo("INFO", "BOOK RETURNED\n" + str(Rental.printReturned(self.__Rcontroller.getRental(int(ID.get())))))
        except ArithmeticError as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def return_book(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter rental ID:")
        label.pack()
        ID = Entry(window)
        ID.pack()
        ID.focus_set()
        buton = Button(window, text="Return book", command=lambda: self.both_return(ID))
        buton.pack()

    def searchBook(self, s):
        try:
            self.__Bcontroller.searchBook(s)
            self.toggle_text(s)
        except Exception as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def toggle_text(self, s):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=420, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Bcontroller.searchBook(s):
            listbox.insert(END, x)

    def search_book(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter keywords:")
        label.pack()
        substring = Entry(window)
        substring.pack()
        substring.focus_set()
        buton = Button(window, text="Search book", command=lambda: self.searchBook(substring.get()))
        buton.pack()

    def toggle_client(self, s):
        window = Toplevel(self.master)
        window.pack_propagate(0)
        listbox = Listbox(window)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Ccontroller.searchClient(s):
            listbox.insert(END, x)

    def searchClient(self, s):
        try:
            self.__Ccontroller.searchClient(s)
            self.toggle_client(s)
        except Exception as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def search_client(self, event):
        window = Toplevel(self.master, width=420, height=420)
        window.pack_propagate(0)
        label = Label(window, text="enter keywords:")
        label.pack()
        substring = Entry(window)
        substring.pack()
        substring.focus_set()
        buton = Button(window, text="Search client", command=lambda: self.searchClient(substring.get()))
        buton.pack()

    def most_rentedBooks(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=500, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Rcontroller.mostRentedBooks():
            listbox.insert(END, x)

    def most_active(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=500, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Rcontroller.mostActiveClients():
            listbox.insert(END, x)

    def most_rentedAut(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=500, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Rcontroller.mostRentedAuthors():
            listbox.insert(END, x)

    def late_rentals(self, event):
        window = Toplevel(self.master, width=500, height=420)
        window.pack_propagate(0)
        listbox = Listbox(window, width=500, height=420)
        listbox.pack_propagate(0)
        listbox.pack()
        for x in self.__Rcontroller.lateRentals():
            listbox.insert(END, x)

    def both_undo(self):
        try:
            self.__Ucontroller.undo()
            messagebox.showinfo("INFO", "Last command was undone")
        except Exception as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def undo(self, event):
        self.both_undo()

    def both_redo(self):
        try:
            self.__Ucontroller.redo()
            messagebox.showinfo("INFO", "Last command was redone")
        except Exception as exc:
            window = Toplevel(self.master)
            window.pack_propagate(0)
            v = StringVar()
            v.set(str(exc))
            label = Label(window, textvariable=v)
            label.pack()

    def redo(self, event):
        self.both_redo()
