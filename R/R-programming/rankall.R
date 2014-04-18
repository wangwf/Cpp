##
rankall <- function(outcome, num){
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  outcomes <-c("heart attack", "heart failure", "pneumonia")
  indics   <-c(11, 17, 23)
  
  ## Check state and outcome are valid
  if (!state %in% data$State) stop("invalid state")
  if (!outcome %in% outcomes) stop("invalid outcome")
  
  i <- indics[match(outcome, outcomes)]
  
  hospitals <- data[data$State == state, c(2,7,i)]
  hospitals[,3] <- as.numeric(hospitals[,3])
  names(hospitals)<- c("name", "state","deathRate")
  #  hospitals <- na.omit(hospitals)
  
  a<- rank(hospitals[,2], na.last=NA)
  
  if (num =="best"){
    r <- 1
  } else if( num =="worst"){
    r<- length(a)
  }else if (num <= length(a)){
    r <- num
  }else{
    if (is.na(num)) stop("invalid num")
    return(NA)
  }
  return(hospitals$name[order(hospitals$deathRate, hospitals$name)[r]])