#include "splayTree.h"

Node* newNodeSplay(int key) 
{
  Node* node  = (Node*)malloc(sizeof(Node));
  node->key   = key;
  node->left  = NULL;
  node->right = NULL;
  return node;
}

Node* rightRotateSplay(Node* x) 
{
  Node* y  = x->left;
  x->left  = y->right;
  y->right = x;
  return y;
}

Node* leftRotateSplay(Node* x) 
{
  Node* y  = x->right;
  x->right = y->left;
  y->left  = x;
  return y;
}

Node* splay(Node* root, int key) 
{
  if (root == NULL || root->key == key)
    return root;

  if (root->key > key) 
  {
    if (root->left == NULL)
        return root;

      if (root->left->key > key) 
      {
        root->left->left = splay(root->left->left, key);
        root = rightRotateSplay(root);
      } 
      else 
      {
        root->left = splay(root->left, key);
      }

    return (root->left == NULL) ? root : rightRotateSplay(root);
  } 
  else 
  {
    if (root->right == NULL)
      return root;

    if (root->right->key < key) 
    {
      root->right->right = splay(root->right->right, key);
      root = leftRotateSplay(root);
    } else 
    {
      root->right = splay(root->right, key);
    }

    return (root->right == NULL) ? root : leftRotateSplay(root);
  }
}

Node* insertSplay(Node* root, int key) 
{
  if (root == NULL)
    return newNodeSplay(key);

  root = splay(root, key);

  if (root->key == key)
    return root;

  Node* node = newNodeSplay(key);

  if (root->key > key) 
  {
    node->right = root;
    node->left  = root->left;
    root->left  = NULL;
  } 
  else
  {
    node->left  = root;
    node->right = root->right;
    root->right = NULL;
  }

  return node;
}

Node* deleteSplay(Node* root, int key) 
{
    if (root == NULL) return root;

    // Сначала находим узел с ключом key
    root = splay(root, key);

    // Если узел не найден, возвращаем корень
    if (root->key != key) return root;

    // Если узел не имеет детей, освобождаем память и возвращаем NULL
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    // Если узел имеет одного ребенка, удаляем узел и возвращаем его ребенка
    if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        Node* temp = root->left;
        free(root);
        return temp;
    }

    // Если узел имеет двух детей, находим максимальный узел в левом поддереве
    Node* temp = root->left;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    // Копируем значение максимального узла в корневой узел
    root->key = temp->key;

    // Удаляем максимальный узел из левого поддерева
    root->left = deleteSplay(root->left, temp->key);

    return root;
}

double measureTime(Node* root, int numInserts, int numDeletes) 
{
  clock_t start, end;
  double insertTime = 0.0, deleteTime = 0.0;

  // Вставки
  start = clock();
  for (int i = 0; i < numInserts; i++) {
      root = insertSplay(root, rand());
  }
  end = clock();
  insertTime = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Удаления
  start = clock();
  for (int i = 0; i < numDeletes; i++) {
      root = deleteSplay(root, rand());
  }
  end = clock();
  deleteTime = ((double)(end - start)) / CLOCKS_PER_SEC;

  return insertTime + deleteTime;
}

int main() 
{
    srand(time(NULL));

    const int numTests = 10;
    const int maxSize = 1000000;
    const int numIterations = 5;

    double insertTimes[numTests];
    double deleteTimes[numTests];

    for (int i = 0; i < numTests; i++) {
        int size = (i + 1) * 100000;
        double totalInsertTime = 0.0, totalDeleteTime = 0.0;

        for (int j = 0; j < numIterations; j++) {
            Node* root = NULL;
            double time = measureTime(root, size, size / 2);
            totalInsertTime += time;
            totalDeleteTime += time;
        }

        insertTimes[i] = totalInsertTime / numIterations;
        deleteTimes[i] = totalDeleteTime / numIterations;

        printf("Size: %d, Average Insert Time: %.6f, Average Delete Time: %.6f\n", size, insertTimes[i], deleteTimes[i]);
    }
    return 0;
}
