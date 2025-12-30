//So the qn is if  only the output of a likined list loop is given  with unknown loopp range .How do you find the  no of loop carried out.
//Hint: we count the output until a null value is reached.We are only givn head and we need to make current link to caluculate  the no of loop.

////My logic
// PSEUDO CODE:
// count = 0
// ptr = head
// while(ptr != NULL)
//     count++
//     ptr = ptr.link (this helps to direct to the next node)
// return count





///Sir's logic
// PSEUDO CODE:
// get_length(&head){
//     count=0;
//     if(head==NUll){some code is required}
//         ptr=head
//         while(ptr!=NULL){
//             count ++;
//             ptr=ptr.link
//         }
//         return count
//     }



///Next qn to print every data present in everynode in the linkedlist

//Pseudo
// PSEUDO CODE:
// count = 0
// ptr = head
// while(ptr != NULL)
//     count++
//     ptr = ptr.link (this helps to direct to the next node)
// return count
//yesh ko tala print(ptr.data) [sabai data print hunxa]


///To insert a new node infront of the existing first node and the inserted node should also be linked with the link("Insertion at the front.")[level - easy]

// PSEUDO CODE:
// Create ptr = malloc(...)
// ptr.data = value
// ptr.link = head    // Point new node to current first node
// head = ptr         // Make new node the new head





//TO put the node at the last with linking all the nodes.

// PSEUDO CODE:
//To insert at last  of the linklist

// if(head==null){}
// ptr=head;
// while(ptr != null){
// 
//     ptr=prt.link;
// }
// prt.link=current





///insertion random(GIVEN IN A QN ) to insert b in between a  and c node .given the data of a=77


//My logic
// PSEUDO CODE:
// Create new_node = malloc(...)
// new_node.data = value
// 
// ptr = head
//     if(ptr.data == 77)        // Find node A with data=77
//         new_node.link = ptr.link   // Point new node to C
//         ptr.link = new_node        // Point A to new node


//Sir's logic  ptr=a=adrres of node
// while(ptr.data!=77){
// ptr.ptr.link


// }
//current.link=ptr
//ptr.link=curren




///To insert after k node.(example 4 node)
//hint to cout and insert as done before.
