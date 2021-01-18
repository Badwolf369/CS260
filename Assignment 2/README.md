# Queue Data Structure

To work with a queue data structure we will only need 3 functions:
- 'create_queue()' Allocates the nesssary memory and returns the address
- 'add_data()' Add information to the end of the queue
- 'get_data()' Remove the oldest added item in the queue
and x variables:
- 'Qmax' Integer containing the max size of the queue
- 'Qlen' Integer containing the current number of items in the queue
- 'Qaddress' Pointer containing first position in the queue's allocation
- 'QAddPos' Number of spaces from address too add new data
- 'QGetPos' Number of spaces from address to get data

add_data()
 
    add_data(int* Qaddress, int data)
    {
        if list is full:
            "Error! No room in Queue"
            return -1
        else:
            place data into Qaddress offset by QAddPos
            increment QAddPos
            increment Qlen
            if QAddPos walks off the end of the list:
                QAddPos = 0
       return 0
    }

get_data

    get_data(int* Qaddress)
    {
        if list is empty:
            "Error! No information in Queue"
            QAddPos = 0
            QGetPos = 0
            return null
        else:
            pull data from Qaddress offset by QGetPos and place it into a variable named 'data'
            set the data at Qaddress offset by QGetPos to null
            increment QGetPos
            decrement Qlen
            if QGetPos walks off the end of the list:
                QGetPos = 0
            if list is empty:
                QAddPos = 0
                QGetPos = 0
        return data
    }





