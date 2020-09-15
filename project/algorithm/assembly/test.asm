
;测试函数   三个数相加  
;.386
.model flat, c
;public test_

.code

test_ proc

;初始化栈帧指针
    push ebp
    mov ebp,esp
;加载参数值
    mov eax,[ebp+8]
    mov ecx,[ebp+12]
	add eax,ecx
    mov ecx,[ebp+16]
	add eax,ecx

;求和
    ; add eax,ecx
    ; add eax,edx
	
	mov ah,01H


;恢复父函数的栈帧指针

    pop ebp
    ret


test_ endp
end


