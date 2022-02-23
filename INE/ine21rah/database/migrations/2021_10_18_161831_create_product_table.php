<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateProductTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('Product', function (Blueprint $table) {
            $table->id();
            $table->string('name',255)->nullable(false)->unique();
            $table->string('description',255)->nullable(true);
            $table->string('imgurl',255)->nullable(false);
            $table->float('price',8,2)->nullable(false);
            $table->float('discountPercent',5,2)->nullable(true);
            $table->dateTime('discountStart_at')->nullable(true);
            $table->dateTime('discountEnd_at')->nullable(true);
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('Product');
    }
}
