(define (make-rat m n)
  (cons m n))

(define (sum-rat m n)
  (cons (+ (car m) (car n)) (+ (cdr m) (cdr n))))
(define (sub-rat m n)
  (cons (- (car m) (car n)) (- (cdr m) (cdr n))))

(define (mul-rat m n)
  (cons (+ (* (car m) (car n))
           (* (cdr m) (cdr n) 5))
        (+ (* (car m) (cdr n))
           (* (cdr m) (car n)))))

(define (gcd-rat m n)
  (cons (/ (car m) (car n))
        (/ (cdr m) (car n))))

;m^n
(define (pow-rat m n)
  (if (= n 0) (make-rat 1 0)
      (mul-rat m (pow-rat m (- n 1)))))

(define x1 (make-rat 1 +1))
(define x2 (make-rat 1 -1))

(define (fn n)
  (car (gcd-rat (mul-rat (sub-rat (pow-rat x1 n)
                                  (pow-rat x2 n))
                         (make-rat 0 1/5))
                (pow-rat (make-rat 2 0) n))))
     
