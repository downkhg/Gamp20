#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h> //OpenSSL���̺귯���� �����ؾ� ����Ҽ��ִ�.(���̺귯����ġ����� ���۸�)
#include <map>

using namespace std;

unsigned char result[MD5_DIGEST_LENGTH];

// Print the MD5 sum as hex-digits.
void print_md5_sum(unsigned char* md) {
    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");
}

void DM5TestMain()
{
    const int SIZE = 1024;
    unsigned char buffer[SIZE];
    unsigned char dm5_buffer[SIZE];

    for (int i = 0; i < SIZE; i++)
        buffer[i] = i;
    memcpy_s(buffer, SIZE, "The quick brown fox jumps over the lazy dog.", SIZE);
    printf("%s\n", buffer);
    unsigned char* dm5_result = MD5((unsigned char*)buffer, SIZE, result);
    memcpy_s(dm5_buffer, SIZE, dm5_result, SIZE);

    print_md5_sum(dm5_buffer);
}

union HASHDATA
{
    unsigned int nData;
    unsigned char buffer[4];
    HASHDATA(int data = 0) { nData = data; }
};

HASHDATA DM5_HASHDATA(HASHDATA uData)
{
    HASHDATA uResult;
    
    unsigned char* dm5_result = MD5(uData.buffer, sizeof(HASHDATA),result);
    memcpy_s((void*)uResult.buffer,sizeof(HASHDATA), dm5_result, sizeof(HASHDATA));

    return uResult;
}

int DM5HashFucntion(int data)
{
    HASHDATA uData(data);
    HASHDATA uResult = DM5_HASHDATA(uData);
    return uResult.nData;
}

void UHASHDATATestMNain()
{
    HASHDATA uHashKey(2);
    print_md5_sum(uHashKey.buffer);
    HASHDATA uData = DM5_HASHDATA(uHashKey);
    print_md5_sum(uData.buffer);
    printf("[%u]:%u\n", uHashKey.nData, uData.nData);
}
//���� �ߺ����� �������������Ƿ� ��ȭ�� ���� ������ �����ϹǷ�, �ʿ� ����� ������ �ߺ��� ������.
void BirthDayTestMain()
{
    unsigned int SIZE = 999999;
    map<unsigned int, unsigned int> map;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        map[DM5HashFucntion(i)] = i;
        if(i % 1000 == 0)printf("%u\n",i);
    }

   printf("mapSize:%u\n",map.size());
   printf(":%u / %f\n", SIZE -map.size(), (float)(SIZE - map.size())/(float)SIZE);
}

int main(int argc, char* argv[]) 
{
    //DM5TestMain();
    //UHASHDATATestMNain();
    BirthDayTestMain();

    return 0;
}