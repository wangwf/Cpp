## Put comments here that give an overall description of what your
## functions do

## Write a short comment describing this function
makeCacheMatrix <- function(x = matrix()) {
    invM <- NULL
    set <- function(y){
        x <<- y
        invM <<- NULL
    }
    get <- function() x
    setinvM <- function(invMatrix) invM <<- invMatrix
    getinvM  <- function() invM
    list(set = set, get = get,
         setinvM = setinvM,
         getinvM = getinvM)
}


## Write a short comment describing this function

cacheSolve <- function(x, ...) {
        ## Return a matrix that is the inverse of 'x'
    invM <- x$getinvM()
    if(!is.null(invM)){
        message("getting cached data")
        return(invM)
    }
    data <- x$get()
    invM <-solve(data) # ginv(data) in MASS package
    x$setinvM(invM)
    invM
}

## test from 
x<-rbind(c(1, -1/4), c(-1/4, 1))  
xMat<-makeCacheMatrix(x)
invxM <-cacheSolve(xm)
x %*% invxM
