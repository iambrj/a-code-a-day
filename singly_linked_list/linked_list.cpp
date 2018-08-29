NODE NULL_NODE{-1,0}; //sentinal
linked_list::linked_list()
{
	HEAD = &NULL_NODE;
	SIZE = 0;
}
bool linked_list::insert_after(NODE node, NODE new_node)
{
	if(HEAD == 0) return false;
	NODE* curr = HEAD;
	while(curr->key != node.key) curr = curr->next;
	NODE* insert = new NODE;
	insert->next = curr->next;
	insert->key = new_node.key;
	curr->next = insert;
	SIZE++;
	return true;
}
void linked_list::insert_beginning(NODE new_node)
{
	if(HEAD->key == -1)
	{
		NODE* insert = new NODE;
		insert->key = new_node.key;
		insert->next = &NULL_NODE;
		HEAD = insert;
		SIZE++;
	}
	else
	{
		NODE* insert = new NODE;
		insert->key = new_node.key;
		insert->next = HEAD;
		HEAD = insert;
		SIZE++;
	}
}
bool linked_list::remove_after(NODE node)
{
	if(HEAD == 0) return false;
	NODE* curr = HEAD;
	while(curr->key != node.key && curr->next!= 0) curr = curr->next;
	if(curr->next == 0) return false;
	NODE* to_del = curr->next;
	curr->next = curr->next->next;
	delete to_del;
	SIZE--;
	return true;
}
bool linked_list::remove_beginning()
{
	if(HEAD == 0) return false;
	NODE* to_del;
	to_del = HEAD;
	HEAD = HEAD->next;
	delete to_del;
	SIZE--;
	return true;
}
void linked_list::display() const
{
	NODE* curr = HEAD;
	while(curr->next->key != -1)
	{
		std::cout<<curr->key<<"->";
		curr = curr->next;
	}
	std::cout<<curr->key<<std::endl;
}
