## Put comments here that give an overall description of what your
## functions do

## Write a short comment describing this function

makeCacheMatrix <- function(x = matrix()) {
    invM <- NULL
    set <- function(y){
        x <<- y
        invM <<- NULL
    }
    get <- function() invM
    setinvM <- function(invMatrix) invM <<- invMatrix
    getinM  <- function() invM
    list(set = set, get = get,
         setinvM = setinvM,
         getinvM = getinvM)
}


## Write a short comment describing this function

cacheSolve <- function(x, ...) {
        ## Return a matrix that is the inverse of 'x'
    invM <- x$getinM()
    if(!is.null(invM)){
        message("getting cached data")
        return(invM)
    }
    data <- x$get()
    invM <-solve(data) 
    x$setinvM(invM)
    invM
}
