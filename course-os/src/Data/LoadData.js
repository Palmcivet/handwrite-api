import { relocate } from '../Config/config';

/**
 * @param {Number} base - 默认 0x0，基址地址
 */
function LoadData(base = 0x0) {
    let process_1 = new Array(
        [
            "mov ebp, esp",
            "sub esp, 48h",
            "push esi",
        ],
        [
            "mov edx" + relocate(0x00002507, base),
        ],
        [
            "pop edi",
            "lea edi, [ebp-48h]",
        ],
        [
            "mov eax" + relocate(0x00002C04, base),
            "mov ebx" + relocate(0x0000BEA0, base)
        ],
        [
            "rep stos dword ptr [edi]",
            "pop ecx",
            "add eax, dword ptr [ebp+8]",
        ],
        [
            "mov eax" + relocate(0x00002758, base)
        ],
        [
            "pop edi",
            "pop esi",
        ],
        [
            "mov eax" + relocate(0x0000A2C8, base)
        ],
        [
            "pop edi",
        ],
        [
            "mov eax" + relocate(0x0000CAB1, base)
        ],
        [
            "mov esp, ebp",
            "pop ebp",
            "ret 4",
        ]
    );

    let process_2 = new Array(
        [
            "push ebp",
            "mov ebp, esp",
            "sub esp, 48h",
            "push esi",
        ],
        [
            "mov edx" + relocate(0x00515C07, base),
        ],
        [
            "pop edi",
            "push ecx",
            "lea edi, [ebp-48h]",
            "mov ecx, 12h",
        ],
        [
            "mov eax" + relocate(0x0357AC03, base),
            "mov ebx" + relocate(0x185BEA00, base)
        ],
        [
            "rep stos dword ptr [edi]",
            "pop ecx",
            "mov dword ptr [ebp-4],ecx",
            "add eax, dword ptr [ebp+8]",
        ],
        [
            "mov eax" + relocate(0x00027958, base)
        ],
        [
            "pop edi",
            "pop esi",
            "pop ecx",
        ],
        [
            "mov eax" + relocate(0x05A2C9B8, base)
        ],
        [
            "pop edi",
        ],
        [
            "mov eax" + relocate(0x0025CAB1, base)
        ],
        [
            "mov esp, ebp",
            "pop ebp",
            "ret 4",
        ]
    );

    let shellcode = new Array(
        [
            "xor ecx, ecx",
            "mul ecx",
            "push ecx",
        ],
        [
            "push 0x0x68732f2f",
            "push 0x0x6e69622f",
        ],
        [
            "mov ebx, esp",
            "mov al, 0xb",
            "int 0x80",
        ]
    );
    return process_1
}

const process_2 = {
    addr: {
        1: 0x00005C07,
        3: 0x0000AC03,
        4: 0x0000EA00,
        6: 0x00007958,
        8: 0x0000C9B8,
        10: 0x0000CAB1,
    },
    code: [[
        "push ebp",
        "mov ebp, esp",
        "sub esp, 48h",
        "push esi",
    ], [
        "mov edx",
    ], [
        "pop edi",
        "push ecx",
        "lea edi, [ebp-48h]",
        "mov ecx, 12h",
    ], [
        "mov eax"
    ], [
        "mov ebx",
    ], [
        "rep stos dword ptr [edi]",
        "pop ecx",
        "mov dword ptr [ebp-4],ecx",
        "add eax, dword ptr [ebp+8]",
    ], [
        "mov eax"
    ], [
        "pop edi",
        "pop esi",
        "pop ecx",
    ], [
        "mov eax"
    ], [
        "pop edi",
    ], [
        "mov eax"
    ], [
        "mov esp, ebp",
        "pop ebp",
        "ret 4",
    ]]
};

export { LoadData }