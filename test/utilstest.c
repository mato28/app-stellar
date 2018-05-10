/*******************************************************************************
 *   Ledger Stellar App
 *   (c) 2017 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#include <stdio.h>
#include <string.h>
#include "stellar_api.h"

void test_print_amount(uint64_t amount, char *expected) {
    char *asset = "XLM";
    char printed[24];
    print_amount(amount, asset, printed);

    if (strcmp(printed, expected) != 0) {
        printf("test_print_amount failed. Expected: %s; Actual: %s\n", expected, printed);
    }
}

void test_print_int(uint64_t id, char* expected) {
    char printed[24];
    print_int(id, printed);
    if (strcmp(printed, expected) != 0) {
        printf("test_print_int_memo failed. Expected: %s; Actual: %s\n", expected, printed);
    }
}

void test_print_summary(char *msg, char *expected) {
    char summery[27];
    print_summary(msg, summery, 12, 12);
    if (strcmp(summery, expected) != 0) {
        printf("test_print_summary failed. Expected: %s; Actual: %s\n", expected, summery);
    }
}

void test_print_hash(uint8_t *hash, char *expected) {
    char hex[16];
    print_hash_summary(hash, hex);
    if (strcmp(hex, expected) != 0) {
        printf("test_print_hash failed. Expected: %s; Actual: %s\n", expected, hex);
    }
}

void test_print_bits(uint32_t in, char *expected) {
    char s[13];
    print_bits(in, s);
    if (strcmp(s, expected) != 0) {
        printf("test_print_bits failed. Expected: %s; Actual: %s\n", expected, s);
    }
}

int main(int argc, char *argv[]) {

    test_print_amount(1, "0.0000001 XLM");
    test_print_amount(10000000, "1 XLM");
    test_print_amount(100000000000001, "10000000.0000001 XLM");
    test_print_amount(100000001, "10.0000001 XLM");
    test_print_amount(100000001000000, "10000000.1 XLM");

    test_print_int(1, "1");
    test_print_int(12, "12");
    test_print_int(100, "100");

    test_print_summary("GADFVW3UXVKDOU626XUPYDJU2BFCGFJHQ6SREYOZ6IJV4XSHOALEQN2I", "GADFVW3UXVKD..4XSHOALEQN2I");

    uint8_t hash[32];
    uint8_t i;
    for (i = 0; i < 32; i++) {
        hash[i] = i;
    }
    test_print_hash(hash, "00010203..1C1D1E1F");

    uint32_t flags = (1 << 0) | (1 << 1);
    test_print_bits(flags, "011");
    return 0;

}
