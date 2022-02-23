<!doctype html>
    <html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <body>
        <!-- HEADER -->
        @include('layouts.header')

        <!-- CENTER AND RIGHT CONTENT -->
        <div class="row">
            <div class="col-9">
                <div class="container-flow" style="margin-top:50px;margin-left:30px">
                    <h3 class="h3">Ofertas del día</h3>
                    <div class="row">
                        @yield('content-center')
                    </div> 
                </div>
            </div>

            <div class="col-3 ">
                <div class="container-flow"style="margin-top:50px;margin-left:30px ">
                    <h3 class="text-center">Lo más vendido</h3>
                    <div class="row">
                        @yield('content-right')
                    </div>     
                </div> 
            </div>
        </div>

        <!-- Loading Javascripts -->   
        <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
        <script>window.jQuery || document.write('https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous">')</script>
        <!-- <script src="../../assets/js/vendor/popper.min.js"></script> -->
        <script src="js/bootstrap.min.js"></script>
        <!-- FOOTER -->
        @include('layouts.footer')
    </body>
</html>