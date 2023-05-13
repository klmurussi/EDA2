node* remove (node* root, key k) {
    if (root->left == NULL && root->right == NULL) {
        return NULL;
    }

    if (k < root->key) remove (root->left, k);
    else if (k > root->key) remove (root->right, k);
    else {
        if (root->left == NULL) {
            node* aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL) {
            node* aux = root->left;
            free(root);
            return aux;
        }
        else {
            node* aux = root->left, aux2 = root;
            while (aux->right != NULL) {
                aux2 = aux; aux = aux->right;
            }
            if (aux == root->left) {
                aux->right = root->right;
            }
            else {
                aux2->right = aux->left;
                aux->left = root->left;
            }

            free(root);
            return aux;
        }
    }
}

int main () {


    
}