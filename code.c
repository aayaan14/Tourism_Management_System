
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Location
{
  INDIA,
  ABROAD
};

struct Destination
{
  char name[50];
  int cost;
  float ratings;
  enum Location location;
  struct Destination *left;
  struct Destination *right;
};

struct Destination *createDestination(char *name, int cost, float ratings, enum Location location)
{
  struct Destination *destination = (struct Destination *)malloc(sizeof(struct Destination));
  strcpy(destination->name, name);
  destination->cost = cost;
  destination->location = location;
  destination->ratings = ratings;
  destination->left = NULL;
  destination->right = NULL;
  return destination;
}

struct Destination *insertCostDestination(struct Destination *root, char *name, int cost, float ratings, enum Location location)
{
  if (root == NULL)
    return createDestination(name, cost, ratings, location);
  if (cost <= root->cost)
    root->left = insertCostDestination(root->left, name, cost, ratings, location);
  else
    root->right = insertCostDestination(root->right, name, cost, ratings, location);
  return root;
}

struct Destination *insertRatDestination(struct Destination *root, char *name, int cost, float ratings, enum Location location)
{
  if (root == NULL)
    return createDestination(name, cost, ratings, location);
  if (ratings>= root->ratings)
    root->left = insertRatDestination(root->left, name, cost, ratings, location);
  else
    root->right = insertRatDestination(root->right, name, cost, ratings, location);
  return root;
}

void inOrderTraversal(struct Destination *root)
{
  if (root == NULL)
    return;
  inOrderTraversal(root->left);
  printf("Destination: %s, Cost: %d, Ratings=%f Location: %s\n", root->name, root->cost, root->ratings, (root->location == INDIA) ? "India" : "Abroad");
  inOrderTraversal(root->right);
}

void bill(struct Destination *root)
{
  printf("The bill for your destination is\n");
}

void cost_display()
{
  struct Destination *root = NULL;

  root = insertCostDestination(root, "Goa", 5000, 5, INDIA);
  root = insertCostDestination(root, "Manali", 6000, 4.5, INDIA);
  root = insertCostDestination(root, "Paris", 20000, 3.2, ABROAD);
  root = insertCostDestination(root, "New York", 25000, 4.9, ABROAD);
  root = insertCostDestination(root, "Thailand", 15000, 2.5, ABROAD);

  inOrderTraversal(root);
}

void rat_display()
{
  struct Destination *root = NULL;

  root = insertRatDestination(root, "Goa", 5000, 5, INDIA);
  root = insertRatDestination(root, "Manali", 6000, 4.5, INDIA);
  root = insertRatDestination(root, "Paris", 20000, 3.2, ABROAD);
  root = insertRatDestination(root, "New York", 25000, 4.9, ABROAD);
  root = insertRatDestination(root, "Thailand", 15000, 2.5, ABROAD);

  inOrderTraversal(root);
}

int main()
{
  printf("\tWelcome to Trip Advisor!!!\n");
  int ch;
  for (;;)
  {
    printf("\n Enter the given choice: \n");
    printf("1. To search your preferred destination\n");
    printf("2. To add in a particular destination\n");

    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      int c;
      printf("\n\tWelcome to the User Mode\n");
      printf("\n1.To display available Packages");
      printf("\n2.To select a package based on cost");
      printf("\n3.To select a package based on ratings\n");

      scanf("%d", &c);
      if (c == 1)
      {
        printf("\nBased on Cost-\n");
        cost_display();

        printf("\nBased on Ratings-\n");

        rat_display();
      }

      break;

    case 2:

    default:
      printf("\nThank you for visiting us!!!\n");
      exit(0);
    }
  }

  return 0;
}
