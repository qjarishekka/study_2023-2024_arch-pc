let stroka2 = '23 2+3 2++3 2+++3 445 677'

document.getElementById("stroka2").innerHTML = stroka2

function task2(){

    let words = stroka2.split(" ")
    let answer = ""


    for(let i = 0 ; i < words.length ; i++){

       

        if(words[i].charAt(0) == "2" && words[i].charAt(words[i].length-1) == "3"  ){

            answer = answer + ' ' + words[i]

         }
    }

    document.getElementById("answer2").innerHTML = `task 2 : ${answer}`

}
