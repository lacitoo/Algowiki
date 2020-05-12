#include <stdio.h>

int main(){
    int nSongs, cdCapacity, length, content=0,cds=1,aktSong=0;

    scanf("%d",&nSongs);
    scanf("%d",&length);
    scanf("%d",&cdCapacity);

    while(aktSong<nSongs){
        content++;
        if(content*length+content-1<=cdCapacity){
            aktSong++;
        }else{
            if(content%13==0){
                --aktSong;
                //printf("This is bad\n");
            }
            ++cds;
            content=0;
        }
        //printf("%d.song: content:%d, cds:%d\n",aktSong,content,cds);
        if(aktSong==nSongs && content%13==0 && content>0){
            --aktSong;
            //printf("This is bad luck\n");
            ++cds;
            content=0;
        }
        
    }

    printf("%d",cds);
    
    return 0;
}