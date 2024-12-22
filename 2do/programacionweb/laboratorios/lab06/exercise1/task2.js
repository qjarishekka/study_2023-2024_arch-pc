function task2(){

    let text = ""

    text = document.getElementById("textArea").value
    //text = text.toUpperCase()

    for(let i = 0; i< text.length ; i++){

        if(text[i] == " "){
            
            text =text.slice(0, i)+ " " + text.charAt(i+1).toUpperCase() + text.slice(i+2)
            
        }


    }

    text =text.charAt(0).toUpperCase() + text.slice(1)

    document.getElementById("textArea").value = text
    
}