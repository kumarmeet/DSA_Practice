int count_internal_nodes(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count_internal_nodes(p->lchild);
    y = count_internal_nodes(p->rchild);
    if(p->lchild != NULL || p->rchild != NULL)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int count_leaf(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count_leaf(p->lchild);
    y = count_leaf(p->rchild);
    if(p->lchild == NULL && p->rchild == NULL)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int count_degree_two(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count_degree_two(p->lchild);
    y = count_degree_two(p->rchild);
    if(p->lchild != NULL && p->rchild != NULL)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int count_degree_one(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count_degree_two(p->lchild);
    y = count_degree_two(p->rchild);
    if((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL))
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int count_degree_one_or_two(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count_degree_two(p->lchild);
    y = count_degree_two(p->rchild);
    if(p->lchild || p->rchild)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int count(struct root *p)
{
  int x, y;
  if(p)
  {
    x = count(p->lchild);
    y = count(p->rchild);
    return x + y + 1;
  }
  return 0;
}
