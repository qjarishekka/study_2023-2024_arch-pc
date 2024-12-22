let numeros = [10,-1,4,2,-9,5,12,-6,-10,-15]
document.getElementById("numeros").innerHTML = numeros


function task3(){

    numeros.sort( (itemA , itemB)=>{
        return itemA - itemB
    })


    numeros.reverse()
    
    //console.log(numeros)
    document.getElementById("numeros").innerHTML = `task 3 : ${numeros}` 

}
