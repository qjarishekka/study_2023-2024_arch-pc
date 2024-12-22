function extratequivalent(){

    let val = document.getElementsByTagName("td")
    let days = document.getElementById("days")
    let selecValue = days.value
    

    
    
    for(let i = 0 ; i < 7 ; i++){
    
        let text = val[i*2].textContent
    
    
        if( text.includes(selecValue) ){
            document.getElementById('answer').innerHTML = `task 2 : ${val[i*2 + 1].innerHTML}`
        }
    
    
    }
    
    }
    