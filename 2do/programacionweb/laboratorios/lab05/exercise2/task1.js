function task1(){

    let numeroLimite = document.getElementById("limit").value
    
    let res = minCMRange(numeroLimite)

    document.getElementById("respuestaTask4").innerHTML = `task 1 : ${res}`

}

function maxcd(a , b){
    return b===0 ? a : maxcd(b , a % b)
}

function mincm(a , b){

    return(a * b) / maxcd(a , b)

}


function minCMRange(n){

    let respuesta = 1;

    for( let i = 1; i <= n ; i++ ){

        respuesta = mincm(respuesta , i)

    }

    return respuesta


}
