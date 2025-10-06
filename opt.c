#include <stdio.h>

int main() {
    int n, f, i, j, k, page, pf = 0;
    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);
    int ref[n];
    printf("Enter reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    int frames[f];
    for(i = 0; i < f; i++) frames[i] = -1;

    printf("\nPage replacement sequence:\n");
    for(i = 0; i < n; i++){
        int found = 0;
        for(j = 0; j < f; j++){
            if(frames[j] == ref[i]){
                found = 1;
                break;
            }
        }

        if(!found){
            pf++;
            int idx = -1, farthest = -1;

            // If empty frame exists
            for(j = 0; j < f; j++){
                if(frames[j] == -1){
                    idx = j;
                    break;
                }
            }

            if(idx == -1){
                // Find the page to replace
                for(j = 0; j < f; j++){
                    int nextUse = n;
                    for(k = i+1; k < n; k++){
                        if(frames[j] == ref[k]){
                            nextUse = k;
                            break;
                        }
                    }
                    if(nextUse > farthest){
                        farthest = nextUse;
                        idx = j;
                    }
                }
            }

            frames[idx] = ref[i];
        }

        // Print current frame status
        printf("Step %d: ", i+1);
        for(j = 0; j < f; j++)
            if(frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        if(!found) printf("-> Page Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
    return 0;
}
