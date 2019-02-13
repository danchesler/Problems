void leftView(Node *root)
{
	queue<Node*>q1;
	queue<Node*>q2;

	q1.emplace(root);

	while (!q1.empty())
	{
		if (!q1.empty())
			cout << q1.front()->data << " ";
		while (!q1.empty())
		{
			auto t = q1.front();
			q1.pop();
			if (t->left)
				q2.emplace(t->left);
			if (t->right)
				q2.emplace(t->right);
		}

		if (!q2.empty())
			cout << q2.front()->data << " ";
		while (!q2.empty())
		{
			auto t = q2.front();
			q2.pop();
			if (t->left)
				q1.emplace(t->left);
			if (t->right)
				q1.emplace(t->right);
		}
	}
}