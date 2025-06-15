#include <stdio.h>
#include <stdlib.h>

typedef struct node { char c; int f; struct node *l, *r; } node;

node* n(char c, int f) { node *n = malloc(sizeof(node)); n->c=c; n->f=f; n->l=n->r=0; return n; }

void p(int *a, int n) { for(int i=0;i<n;i++) printf("%d",a[i]); printf("\n"); }

void h(node *r, int *a, int t) {
    if (r->l) { a[t]=0; h(r->l,a,t+1); }
    if (r->r) { a[t]=1; h(r->r,a,t+1); }
    if (!r->l && !r->r) { printf("%c: ",r->c); p(a,t); }
}

int main() {
    char d[] = {'a','b','c','d','e','f'};
    int f[] = {5,9,12,13,16,45}, s=6;
    node *x, *y, *z, *h[s]; int i,j;
    
    for(i=0;i<s;i++) h[i]=n(d[i],f[i]);
    for(i=1;i<s;i++) for(j=i;j && h[j]->f<h[j-1]->f;j--) { x=h[j]; h[j]=h[j-1]; h[j-1]=x; }
    
    while(s>1) {
        x=h[0]; y=h[1];
        for(i=0;i<s-2;i++) h[i]=h[i+2];
        z=n('$',x->f+y->f); z->l=x; z->r=y;
        for(i=s-3;i>=0 && z->f<h[i]->f;i--) h[i+1]=h[i];
        h[i+1]=z; s--;
    }
    
    int a[100]; h(h[0],a,0);
    return 0;
}