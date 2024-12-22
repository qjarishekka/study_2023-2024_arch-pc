let answer = ""

function task2(){

    

    let enteringText = document.getElementById("enteringWord").value

    answer += " " +enteringText

    document.getElementById("enteringWord").value = ""

    document.getElementById("answer2").innerText = `task 2 : ${answer}`


}