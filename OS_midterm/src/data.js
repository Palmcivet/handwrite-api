/**
 * 
 * @param {String} method - absolute/reload/dynamic
 * @return {Array}
 */
let Program = (method) => {
    let base = null
    if (method == "absolute") {
        base = 0x00400000
    }
    else if (method == "reload") {
        base = 0x0
    }
    else if (method == "dynamic") {
        base = 0x0
    }
    else {
        return "argument invalid!"
    }
    let process = new Array(
        [
            "push ebp",
            "mov ebp, esp",
            "sub esp, 48h",
            "push ebx",
            "push esi",
            "push edi",
            "push ecx",
            "lea edi, [ebp-48h]",
            "mov ecx, 12h",
        ],
        [
            "mov eax " + String(0x0357AC03 + base)
        ],
        [
            "rep stos dword ptr [edi]",
            "pop ecx",
            "mov dword ptr [ebp-8],edx",
            "mov dword ptr [ebp-4],ecx",
            "mov eax, dword ptr [ebp-4]",
            "add eax, dword ptr [ebp-8]",
            "add eax, dword ptr [ebp+8]"
        ],
        [
            "mov [" + String(0x00027958 + base) + "], eax"
        ],
        [
            "pop edi",
            "pop esi",
            "pop ebx",
            "mov esp, ebp",
            "pop ebp",
            "ret 4",
            "xor ecx, ecx",
            "mul ecx",
            "push ecx"
        ],
        [
            "push " + String(0x08032f2f + base),
            "push " + String(0x0e39622f + base)
        ],
        [
            "mov ebx, esp",
            "mov al, 0xb",
            "int 0x80"
        ]
    )
    return process
}

export { Program }